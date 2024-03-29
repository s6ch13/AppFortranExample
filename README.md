# AppFortranExample
Example of linking fortran code with java code using JNI.  This example passes values from a java method to a fortran subroutine and returns some values back via reference to the java calling method.  

This is a working example that leverages the work done by Willie Wheeler at
https://medium.com/wwblog/java-fortran-integration-using-jni-7376879f45cd and development work at https://www.gemsoftware.org Geotechnical Engineering Modelling Software (GEMS)

Enhancements
------------
1. Common gradle build file for mac and windows
2. Supports 32b and 64b generation
3. Supports JDK v1.8 and above.  (jdk 1.8 is required for 32b code while jdk11/jdk 17 is recommended for 64b
4. Library for passing 2 dimensional arrays between java & fortran.  The library takes care of the row-column difference in storing data in arrays

Prerequisites
-------------
- gfortran for windows you can get gfortran by installing MinGW-w64 or MinGW-w32.

- Java.  You can get open jdk from https://adoptium.net/

- Gradle build https://gradle.org (version < 8.0)

Getting the source
------------------
Download and unzip the folder from the github repo 
https://github.com/s6ch13/AppFortranExample

You can also fork the repository

Contents : 

README.md

LICENSE

settings.gradle

build.gradle		- build file

/src/main/fortran	- contains fortran sources

/src/main/c			- contains c sources

/src/main/java		- contains java sources


edit the build.gradle to point to the correct java & gfortran versions.
You only need the files for the versions you are compiling for

Compiling 
---------


$gradle build

BUILD SUCCESSFUL in 13s

12 actionable tasks: 12 executed

$

This generates the jar file - AddNumbers-mac.jar which can be executed.

The compiled fortran/c libraries are at build/libs/

$ls

AddNumbers-mac.jar	README.md		build			settings.gradle
LICENSE			bin			build.gradle		src

build/libs/mac$ls

lib_addnumbers_driver.so


Running
-------

$java -jar AddNumbers-mac.jar

Example of executing a fortran subroutine from java

5 + 6 = 11

1.0	2.0	

3.0	4.0	

\+

1.0	2.0	

3.0	4.0	

=

2.0	4.0	

6.0	8.0	
