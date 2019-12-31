/*
	AddNumbers.java
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

public class AddNumbers extends FortranInterface {

	static {
		// load the library thats created by compiling the fortran & c code.
		File libForExample = new File(GetLibraryLocation("lib_addnumbers_driver"));

		System.load(libForExample.getAbsolutePath());
		
	}
	
	public AddNumbers() {
	}

	// Declare the native functions to be called from java.
	// variables that need to be passed by reference and updated by fortran
	// need to be passed as arrays
	static synchronized native int add(int a, int b, int[] c);

    static synchronized native int matrixAdd(
    		float[][] a, float[][] b, float[][] c);

}
