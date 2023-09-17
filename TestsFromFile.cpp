#include <stdio.h >

#include "TXLib.h"
#include "InteractiveEquationSolver.h"
#include "MeasurementErrorFile.h"
#include "TestsFromFile.h"

int TestOne(double a, double b, double c, double x1ref, double x2ref, int nRootsref)
  {
  double x1 = 0, x2 = 0;
  int nRoots = SolveSquare(a, b, c, &x1, &x2);

  if ( not(IsEqual(x1, x1ref)) or not(IsEqual(x2, x2ref)) or nRoots != nRootsref)
    {
    printf("FAILED: x1 = %lg, x2 = %lg, nRoots = %d, expected: x1ref = %lg, x2ref = %lg, nRootsref = %d\n", x1, x2, nRoots, x1ref, x2ref, nRootsref);
    return 0;
    }

  else
    {
    printf("Test OK\n");
    return 1;
    }

  }

int Testing()
  {
  FILE *datafile = fopen("datafile.txt", "r");
  int nOKK = 0;

  for (int i; i<NTESTS; i++)
    {
    TestData data1 = {0, 0, 0, 0, 0, 0};

    fscanf(datafile, "%lg%lg%lg%lg%lg%d", &data1.a, &data1.b, &data1.c, &data1.x1ref, &data1.x2ref, &data1.nRootsref);

    nOKK += TestOne(data1.a, data1.b, data1.c, data1.x1ref, data1.x2ref, data1.nRootsref);

    fgets(data1.name, MAXLEN, datafile);

    printf("%lg%lg%lg%lg%lg%d%s", data1.a, data1.b, data1.c, data1.x1ref, data1.x2ref, data1.nRootsref, data1.name);
    }

  fclose(datafile);
  return nOKK;
  }
