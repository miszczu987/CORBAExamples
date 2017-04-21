#!/bin/bash


#CONFIG ========================================================================
INSTALL_TARGET=~/TAO

TAO_ARCHIVE=ACE+TAO-6.4.0.tar.gz


#CONSTANTS =====================================================================
DIR=$(dirname $(readlink -f $0))

TAO_URL=http://download.dre.vanderbilt.edu/previous_versions/$TAO_ARCHIVE
ACE_WRAPPERS="ACE_wrappers"


#FUNCTIONS =====================================================================
function downloadTAO
{
	cd $DIR
	wget $TAO_URL
}

function unpackTAO
{
	cd $DIR
	tar -xvzf $TAO_ARCHIVE
}

function prepareEnvironment
{
	export ACE_ROOT=$DIR/$ACE_WRAPPERS
	export TAO_ROOT=$ACE_ROOT/TAO

	printf "#include \"ace/config-linux.h\"\n" > $ACE_ROOT/ace/config.h

	printf "INSTALL_PREFIX = $INSTALL_TARGET\n" > $ACE_ROOT/include/makeinclude/platform_macros.GNU
	printf "include \$(ACE_ROOT)/include/makeinclude/platform_linux.GNU\n" >>  $ACE_ROOT/include/makeinclude/platform_macros.GNU

	mkdir -p $INSTALL_TARGET
	export LD_LIBRARY_PATH=$ACE_ROOT/lib:$LD_LIBRARY_PATH
}

function makeComponent
{
	cd $1
	make
	cd $DIR
}

function installComponent
{
	cd $1
	make install
	cd $DIR
}

function cleanupTAO
{
	cd $DIR
	rm -Rf $TAO_ARCHIVE $ACE_WRAPPERS
}


#MAIN ==========================================================================
downloadTAO
unpackTAO

prepareEnvironment

makeComponent $ACE_ROOT/ace
makeComponent $ACE_ROOT/apps/gperf
makeComponent $TAO_ROOT/tao

installComponent $ACE_ROOT
installComponent $TAO_ROOT

cleanupTAO

