#! /usr/bin/bash

SCRIPT_PATH="$HOME/.stellarium/scripts"
SRC_PATH="$( cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)/../.."
echo -e \
"\n\nWelcome to the NEMESIS guided tour for Stellarium installation script.\n\
All needed resources are installed in the following directory:\n\n\t${SCRIPT_PATH}\n"

if [ -d "$SCRIPT_PATH" ]; then
	if [ -f "$SCRIPT_PATH/NEMESIS_tour.ssc" ]; then
		CONFIRM="n"
		read -p "It appears as if the NEMESIS tour is already installed on your computer. Do you want to install it anyways? (y/N): " -e CONFIRM
		if [[ ${CONFIRM^^} == "YES" || $CONFIRM == [yY] ]]; then
			echo -e "\nCopying resources from $SRC_PATH to ${SCRIPT_PATH} ..."
			cp -r "${SRC_PATH}/nemesis" "$SCRIPT_PATH"
			cp "${SRC_PATH}/NEMESIS_tour.ssc" "$SCRIPT_PATH"
		else
			echo -e "\nNEMESIS guided tour for Stellarium was not installed. Good bye and have a nice day. :)"
			exit 1
		fi
	else
		echo -e "\nCopying resources from $SRC_PATH to ${SCRIPT_PATH} ..."
		cp -r "${SRC_PATH}/nemesis" "$SCRIPT_PATH"
		cp "${SRC_PATH}/NEMESIS_tour.ssc" "$SCRIPT_PATH"
	fi
else
	echo "script directory not found at installation location. Creating script directory ..."
	mkdir -p $SCRIPT_PATH

	echo -e "\nCopying resources from $SRC_PATH to ${SCRIPT_PATH} ..."
	cp -r "${SRC_PATH}/nemesis" "$SCRIPT_PATH"
	cp "${SRC_PATH}/NEMESIS_tour.ssc" "$SCRIPT_PATH"
fi

echo -e "\nAll done. Good bye and have a nice Day. :)"
