#!/bin/bash

DIR=$(readlink -f $(dirname $0))

source ${DIR}/_name_service
source ${DIR}/_name_service_${NS_PROVIDER}


if ! isNSWorking
then
	echo "NameService not running!"
	exit 1
fi

stopNS

