/*
	App Fortran example 
	
	
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
    	
/*
    This is an example for linking Fortran code with
	Java code.  This borrows a lot of ideas from the blog by Willie Wheeler
	https://medium.com/wwblog/java-fortran-integration-using-jni-7376879f45cd

 */

package appFortranExample;

public class Main {

	public static void main(String[] args) {
		System.out.println("Example of executing a fortran subroutine from java");
		
		int l = 5;
		int m = 6;
		int []n = new int[1];
		
		AddNumbers fEN = new AddNumbers();
		
		int status = fEN.add(l,m,n);

		System.out.printf("%d + %d = %d\n\n",l,m,n[0]);
		
		float[][] matA = {
				{1,2},
				{3,4}};

		float[][] matB = {{1,2},
				{3,4}};
		
		float[][] matC = new float[2][2];
		
		status = fEN.matrixAdd(matA,matB,matC);	
		fEN.displayMatrix(matA);
		System.out.println("+");
		fEN.displayMatrix(matB);
		System.out.println("=");		
		fEN.displayMatrix(matC);
	}
		
	
}