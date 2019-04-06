#!/bin/bash - 
#===============================================================================
#
#          FILE: tr_space.sh
# 
#         USAGE: ./tr_space.sh 
# 
#   DESCRIPTION: https://www.hackerrank.com/challenges/text-processing-tr-3/problem?h_r=next-challenge&h_v=zen
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/13/2019 01:39:02 AM
#      REVISION:  ---
#===============================================================================

cat "$@" | tr -s \ 

