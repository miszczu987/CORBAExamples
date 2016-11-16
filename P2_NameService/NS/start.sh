#!/bin/bash

DIR=$(readlink -f $(dirname $0))

source ${DIR}/_name_service
source ${DIR}/_name_service_provider
source ${DIR}/_name_service_${NS_PROVIDER}


if isNSWorking
then
	echo "NameService already started!"
	exit 1
fi

startNS

