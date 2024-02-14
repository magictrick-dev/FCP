*
*
*
      SUBROUTINE PRIME_SEIVE(N_SIZE) BIND(C, NAME="prime_seive")
          INTEGER*8 :: N_SIZE
          INTEGER*8 :: I_SQUARE
          REAL :: N_SQUARE
          REAL :: R_N
          INTEGER*8 :: NN
          INTEGER*8 :: NI
          INTEGER*8 :: P
          LOGICAL BARR(*)
          POINTER(BP, BARR)
          BP=MALLOC((N_SIZE+1)*4)
          BARR(1)=.FALSE.
          R_N=N_SIZE
          N_SQUARE=SQRT(R_N)
          I_SQUARE=N_SQUARE
          DO 3 I=2,N_SIZE
              BARR(I)=.TRUE.
3         CONTINUE
          DO 1 I=2,I_SQUARE
              NN=I*I
              NI=0
              P=NN + (NI * I)
              DO WHILE (P .LT. N_SIZE+1)
                  BARR(P)=.FALSE.
                  NI=NI+1
                  P=NN+(NI*I)
              END DO
1         CONTINUE
          DO 2 I=1,N_SIZE
              IF (BARR(I) .EQV. .TRUE.) THEN
                  PRINT *,I
              END IF
2         CONTINUE
      END
