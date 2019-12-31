/*
	FortranInterface.java 	
    Copyright (C) 2019  Sriram C.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/ 

package appFortranExample;

import java.io.File;

public class FortranInterface {

	// Operating systems.
	public enum OS {
		WINDOWS, LINUX, MAC, SOLARIS
	};
	
	protected FortranInterface() { }

	// get the library location where the compiled fortran code is stored.
	// win-x86 32b windows code 
	// win-x64 64b windows code
	// mac         macOS code
	public static String GetLibraryLocation(String filename)
	{
		String OS = System.getProperty("os.name");
		String arch = System.getProperty("os.arch").toLowerCase();
		String location = "build/libs/";

		switch(getOS())
		{
		case WINDOWS:
			if ("i386".equals(arch))
				arch = "x86";
			else if("amd64".equals(arch))
				arch = "x64";

			location += "win-" + arch + File.separator + filename+".dll";
			break;
		case MAC:
			location += "mac" + File.separator + filename+".so";
			break;
		default: // Linux / FreeBSD / OpenBSD
			location += System.getProperty("os.name").toLowerCase();
			if ("x86".equals(arch))
				arch = "i386";
			else if ("x86_64".equals(arch))
				arch = "amd64";
			else if ("ARM".equals(arch))
				arch = "arm";

			location += "-" + arch + File.separator + filename+".so";
			break;
		}

		return location;
	}

	// Get the OS running so the appropriate library can be loaded
	// https://stackoverflow.com/questions/228477/how-do-i-programmatically-determine-operating-system-in-java
	private static OS os = null;

	public static OS getOS() {
		if (os == null) {
			String operSys = System.getProperty("os.name").toLowerCase();
			if (operSys.contains("win")) {
				os = OS.WINDOWS;
			} else if (operSys.contains("nix") || operSys.contains("nux")
					|| operSys.contains("aix")) {
				os = OS.LINUX;
			} else if (operSys.contains("mac")) {
				os = OS.MAC;
			} else if (operSys.contains("sunos")) {
				os = OS.SOLARIS;
			}
		}
		return os;
	}

	// Library Routines

	public void populateMatrix(float[][] m,float[][] val) {
		for(int i=0; i<val.length; i++) {
			for (int j=0; j < val[0].length; j++) {
				m[i][j] = val[i][j];
			}
		}
	}

	public void populateArrayInt(int[] m,int[] val) {
		for(int i=0; i<val.length; i++) {
			m[i] = val[i];
		}
	}

	public void populateArrayFloat(float[] m,float[] val) {
		for(int i=0; i<val.length; i++) {
			m[i] = val[i];
		}
	}


	public void populateArrayDouble(double[] m,double[] val) {
		for(int i=0; i<val.length; i++) {
			m[i] = val[i];
		}
	}


	public static void displayMatrix(float[][] m) {

		for(int i=0; i<m.length; i++) {
			for (int j=0; j<m[0].length; j++) {
				System.out.print(m[i][j] + "\t");
			}
			System.out.println();
		}
		System.out.println();
	}


}
