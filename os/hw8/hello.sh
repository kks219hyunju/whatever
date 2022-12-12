#!/bin/bash
## Minimal cgi demo wrapper to show how the CGI environment works.

## dump the env as if it were a shell.
## Human: Look for URL parameters in the output
if [ -z $QUERY_STRING ]
then
	input=poem.txt
else
	input=($QUERY_STRING)
fi

./hw7executable.out -H -L /var/log/OS_logging/hw7log.txt $input
