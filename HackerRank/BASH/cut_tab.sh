#!/bin/bash - 
#===============================================================================
#
#          FILE: cut_tab.sh
# 
#         USAGE: ./cut_tab.sh 
# 
#   DESCRIPTION: https://www.hackerrank.com/challenges/text-processing-cut-5/problem
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (), 
#  ORGANIZATION: 
#       CREATED: 03/13/2019 01:15:31 AM
#      REVISION:  ---
#===============================================================================

cat "$@" |
        cut -d$'\t' -f-3



