
c$$$    AddNumbers.for
c$$$    Copyright (C) 2019  Sriram C.
c$$$
c$$$    This program is free software: you can redistribute it and/or modify
c$$$    it under the terms of the GNU General Public License as published by
c$$$    the Free Software Foundation, either version 3 of the License, or
c$$$    (at your option) any later version.
c$$$
c$$$    This program is distributed in the hope that it will be useful,
c$$$    but WITHOUT ANY WARRANTY; without even the implied warranty of
c$$$    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
c$$$    GNU General Public License for more details.
c$$$
c$$$    You should have received a copy of the GNU General Public License
c$$$    along with this program.  If not, see <https://www.gnu.org/licenses/>.



c       Add 2 numbers A and B and store the result in C
        SUBROUTINE ADD(L,M,N)
        INTEGER L,M,N

        N = L + M

        RETURN
        END

c       Add 2 matrices A and B and store the result in C
C       In this example, we assume the matrices are 2x2 matrices
        SUBROUTINE MATRIXADD(A,B,C)
        REAL A(2,2), B(2,2), C(2,2)

        DO I = 1,2
           DO J = 1,2
              C(I,J)=A(I,J)+B(I,J)
           END DO
        END DO

        RETURN
        END

