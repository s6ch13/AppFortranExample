
c$$$    AddNumbers.for
c$$$    Copyright (C) 2019  Sriram C.
c$$$
c$$$    Redistribution and use in source and binary forms, with or without
c$$$    modification, are permitted provided that the following conditions 
c$$$    are met:
c$$$
c$$$    1. Redistributions of source code must retain the above copyright notice
c$$$    this list of conditions and the following disclaimer.
c$$$    2. Redistributions in binary form must reproduce the above copyright 
c$$$    notice, this list of conditions and the following disclaimer in the 
c$$$    documentation and/or other materials provided with the distribution.
c$$$
c$$$    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
c$$$    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
c$$$    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A 
c$$$    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
c$$$    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
c$$$    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
c$$$    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
c$$$    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
c$$$    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
c$$$    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY 
c$$$    WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
c$$$    OF SUCH DAMAGE. 


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

