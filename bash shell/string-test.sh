#string checks

str1="Hey You!"
str2="What's up?"
str3=
str4=""


[ "$str1" = "$str2" ]
	echo $?

[ "$str1" != "$str2" ]
	echo $?
[ -n "$str3" ]
	echo $?
[ -z "$str1" ]
	echo $?
