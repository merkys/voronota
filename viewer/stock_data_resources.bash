#!/bin/bash

cd $(dirname "$0")

function write_resource_file
{
	NAME=$1
	FILE=$2
	echo "inline const char* ${NAME}()"
	echo "{"
	echo "static const char value[]={"
	cat "$FILE" | xxd -i | sed -e '$s/$/, 0x00/'
	echo "};"
	echo "return value;"
	echo "}"
}

{

cat << 'EOF'
#ifndef VIEWER_STOCKED_DATA_RESOURCES_H_
#define VIEWER_STOCKED_DATA_RESOURCES_H_

namespace voronota
{

namespace viewer
{

namespace resources
{
EOF

echo
write_resource_file data_radii ../resources/radii
echo
write_resource_file data_voromqa_v1_energy_means_and_sds ../resources/voromqa_v1_energy_means_and_sds
echo
write_resource_file data_voromqa_v1_energy_potential ../resources/voromqa_v1_energy_potential
echo

cat << 'EOF'
}

}

}

#endif /* VIEWER_STOCKED_DATA_RESOURCES_H_ */
EOF

} > ./src/viewer/stocked_data_resources.h
