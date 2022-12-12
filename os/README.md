# Operating Systems Homework #8 cgi-bin Vulnerability Assessment

Apache Webserver cgi-bin Vulnerability Assessment regards Our implemented Program

Common Gate Interface (CGI) is a resource for accommodating web service to run a script or programs so instead of having to
program separate programs through java-script and work on implementation of such system, and CGI eliminates the need of
the such difficult process by injecting script directly into web service, we are able to run most any programs that exist
within the web server host.

There are a few things that we need to recognize in words that describe of use of cgi-bin.
When it comes to executing programs through script there are a few enviroment components that the operating system may be
exposed to vulnerability attacks or bugs that could cause the system to break in various ways.
Naturally, the operating system carries many loopholes or vulnerabilities, some known by many people, and some that have
not even discovered yet.

There are multiple ways that a server (hosting web service) can be breached
 - Process limits and protections
 - Memory limits and protections
 - CPU limits
 - Network limits
 - File Security risks and limits
 - Possible exploits
 - Possible risks due to programming errors
 - Other aspects of system fragility

Some of these limitations can be overlapped and can be explained together. In this article, Process, memory,
CPU limitations will be explained together, as thus vulnerability of cgi-bin and similar script execution technique
could have these similar occurrences for security breaches.

 1. Physical limitations
 2. Network limitations
 3. Operating systems/program vulnerabilities
 4. Possible exploits, Possible risks due to programming errors
 5. Other aspects of system fragility
 
The physical limitations come from the physical hardware of the web server. Most servers are equipped with multiple
physical CPUs, multiple cores, and multiple threads within those cores. Generally, it is difficult to see these physical
limitations come into play when there are little to no connection requests and communication in the networking spaces, otherwise local communication.
The Program that we have created and implemented into the server has little to no effect on the physical limitations of the
web server, unless the program call is made by a million or trillion users because our program is not running fork capability within our program
when we complied to run in the server.

The network limitations are commonly composed of Denial of Service Attacks that bug down the flow of traffic into the web server when these types of
attacks occur in the web server there are two main goals that attackers usually try to accomplish. one, denial of service by sending millions of traffic
through the network, which will cause clog the network line, and people who try to access the server will not be able to access the server. second, the attacker
is attempting to create a buffer overflow, often attackers attempt buffer overflow to create within physical system exploit to access and modify within memory space.

The exploit we are going to attempt on our system is part of operating systems and program vulnerabilities. In order to attempt this vulnerability we must know
the characteristics of cgi-bin, and our program's loophole.


The program is run by the user inputting an argument while running the program. The user
should run the program by using code like the following example. ```./a.out -r -c "filename"```
One argument is inputted to the program, it will read the size of the file, and read
the time delay in a string, which it will convert into an integer by ```atoi``` function.

The program will repeat this operation until there is no more line to be printed
from the file inserted into the argument by the user. Once this process is completed,
it will close the inputted file via ```fclose``` and ```return 0``` to
close the program.

There are various arguments input through this program.

```
-r[everse], reverse the input of the file and output the file backward
-L[ogging], log the file usage, location of log required
-H[TML], add an HTML tag to enable its operation on web service
```
and program is ran command like this: ```./a.out -rL /var/log/osLogfile.log -H file.txt;```


In the whole operation of our program, our program is able to read whatever is inputted into the program, whether they are in the parent directory
or pointed through an absolute directory.


The executable program is all located under ```/usr/lib/cgi-bin```. Under this folder, there is ```a.out``` for the main executable, ```file.txt``` and ```Tempest.txt``` for the output file.

The main shell script that runs the executable on to webserver is called ```tinycgi.sh```, this shell script contains the code that is pre-defined for the shell to run the executable with certain variables assigned to it, and it must assigned ```chmod 774 tinycgi.sh``` for a shell script to be executed.
```
#!/bin/bash

## Minimal cgi demo wrapper to show how the CGI environment works.
## Header should be in child program, but this is a simple demo

## dump the env as if it were a shell.
## Human: Look for URL parameters in the output

./a.out -rL /var/log/osLogfile.log -H $QUEARY_STRING$ ;

env
```

The script may seem normal but it has a fatal flaw. The executable program is programmed so it takes whatever directory data, it is looking for a file within
the current directory, but the program nor the shell script does not stop the user to insert the absolute directory. Apache web server simply takes in the output of the
program execution and displays it onto the web browser, and all execution is done within the operating system level, which means there is no differentiating between
calling a root file vs user-created files.

For example, the attacker could easily read ```/etc/passwd``` file.

```
http://localhost/cgi-bin/tinycgi.sh=?/etc/passwd
```

When this address line is passed to the server, the server reads this: ```./a.out -rL /var/log/osLogfile.log -H /etc/passwd ;```, which it is being read from
the root directory down. This will enable attackers to read any data on the server by simply taking advantage of the loophole we created within both the shell
script and the program. Additionally, our program offers logging capability and while the shell script defines it, we can easily change the output of the file.
```
http://localhost/cgi-bin/tinycgi.sh=?/etc/passwd -H ~/Documents
```

The server reads this address line like this:```./a.out -rL /var/log/osLogfile.log -H /etc/passwd -H ~/Documents ;```. Technically, we have passed the logging argument
twice and will overwrite the first logging request and write the log file somewhere else, in this case, it will be the Documents folder in the home directory. This vulnerability gives the attacker ability to write and read files at root privilege. While reading capabilities are pretty unlimited at this level, writing is
withint logging purpose and set script that was programmed in the program.


In order to fix the vulnerability our program, argument variable must be altered so it does not interfere with new incoming ```QUERY_STRING```. Thus, when we
run the program from the shell script, we run so that ```./a.out -rL /var/log/osLogfile.log -H $QUEARY_STRING$ ;``` we log first then callin the file we want to read.
There are two things to fix here.
 1. When should log variable be called
 2. Giving fixed directory location so it does not interfere with root files

When we look at url request to exploit the log variable to write on any location, it takes in the very last logging argument and the location that is given, so
order to ensure that log is done properly, we must call it at the very end of the argument. Additionally, we must limit the directory accessed by the user by
passing in a parent directory that we want for them to work or able to play around. After taking consideration of these two factors the correct solution for our
program to operate in more secure manner in the shell script is by
```
./a.out ~/$QUEARY_STRING$ -rHL /var/log/osLogfile.log ;
```

All the arguments for the program is behind ```QUERY_STRING``` so if attacker attempt to replace the argument, they wont be able to do so. And when ```QUERY_STRING``` is
called for specific file, by fixing to the home directory by adding ```~/```, we can eliminate attacker attempting to access the root files.


Back in ```bash``` verison 2.6.0 and below, there was metasploit cgi-bin reverse shell exploit that was able to pass through any command via shell directly
and have root privilage over the server. While the issue between cgi-bin metasploit reverse shell utilizes simliar technique as our cgi-bin vulnerability,
metasploit is able to change the shell script. For example, given that we are using ```bash version 2.5.8```, if we pass in ```QUERY_STRING```

```
http://localhost/cgi-bin/tinycgi.sh=?whatever%;%;%; cat /etc/passwd 
```

This allows the attacker to use any command in shell, regardless of whatever program it is intended for use. So instead of changing the argument variables and
exploiting the program we wrote, we are directly exploiting vulnerability existed in old bash shell. The way that this exploit works is by giving whatever input
into the ```QUERY_STRING``` then commenting out the actual program portion of the script, then we are replacing new line of command after the shell script, thus
for the operating system it would look something like this:
```
#!/bin/bash

## Minimal cgi demo wrapper to show how the CGI environment works.
## Header should be in child program, but this is a simple demo

## dump the env as if it were a shell.
## Human: Look for URL parameters in the output

./a.out -rL /var/log/osLogfile.log -H whatever%;%;
cat /etc/passwd;

env
```

