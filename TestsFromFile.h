#ifndef TESTSFROMFILE_H_INCLUDED
#define TESTSFROMFILE_H_INCLUDED

/// This function checks the correctness of the solution of the quadratic equation program for a specific case
int TestOne(double a, double b, double c, double x1ref, double x2ref, int nRootsref);

/// This function displays to the user the correctness of all tests
int Testing();

const int NTESTS = 7;
const int MAXLEN = 140;

struct TestData
  {
  double a, b, c;

  double x1ref, x2ref;
  int nRootsref;

  char name[MAXLEN];
  };

#endif // TESTSFROMFILE_H_INCLUDED
