#!/bin/bash - 
#===============================================================================
#
#          FILE: png_to_jpg.sh
# 
#         USAGE: ./png_to_jpg.sh 
# 
#   DESCRIPTION: for image in png convert to jpg image.
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 02/12/2017 01:14:35 AM
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

for image in *.png; 
do
	convert "$image" "${image%.png}.jpg"
done
exit 0

