#include "test.h"

#include <fstream>

double average(double * tab, int n){
  double avg=0;
  for (int i = 0; i < n; ++i){
    avg += tab[i];
  }
  avg /= (double) n;
  return avg;
}

void Test::TestClassifySorted(const std::string path_file, int divs){
    Data data;
    double* results = new double[divs];
    data.loadDataFromFile(path_file);
    for( int i=0; i<divs; ++i ){
        Data l_set(data.getLearningSet(i, divs));
        Tree classifier(&l_set);
        classifier.makeTree();
        TestData test_set(data.getTestSet(i, divs));
        test_set.setClassifier(&classifier);
        test_set.classify();
        results[i] = test_set.checkEfficiency();
    }
    for(int i = 0; i<divs; ++i ){
        std::cout << "TestSet[sorted] - Subset: " << i << "/" << divs << "\t result = " << results[i] << "\n";
    }
    delete results;
}

void Test::TestClassifyMixed(const std::string path_file, int divs){
    Data data;
    double* results = new double[divs];
    data.loadDataFromFile(path_file);
    data.mixData();
    for( int i=0; i<divs; ++i ){
        Data l_set(data.getLearningSet(i, divs));
        Tree classifier(&l_set);
        classifier.makeTree();
        TestData test_set(data.getTestSet(i, divs));
        test_set.setClassifier(&classifier);
        test_set.classify();
        results[i] = test_set.checkEfficiency();
    }
    for(int i = 0; i<divs; ++i ){
        std::cout << "TestSet[mixed] - Subset: " << i << "/" << divs << "\t result = " << results[i] << "\n";
    }

    delete results;
}

void Test::TestsRun(const std::string data_file, const std::string results_file){
  Data data;
  data.loadDataFromFile(data_file);

  std::ofstream res;
  res.open (results_file);
  for (int divs = 2 ; divs < 22; ++divs ){
    int N = 10;
    double* crossValidationAverage = new double[N];
    for (int n = 0; n < N; ++n ){
      data.mixData();
      double* results = new double[divs];
      for( int i=0; i<divs; ++i ){
          Data l_set(data.getLearningSet(i, divs));
          Tree classifier(&l_set);
          classifier.makeTree();
          TestData test_set(data.getTestSet(i, divs));
          test_set.setClassifier(&classifier);
          test_set.classify();
          results[i] = test_set.checkEfficiency();
        }

        crossValidationAverage[n] = average(results, divs);

        delete [] results;
    }
    res << "Average accuracy for " << divs - 1 << " learning sets and 1 test set: \t" << average(crossValidationAverage, N) << "\n";
    delete[] crossValidationAverage;
  }

  for (int divs = 2 ; divs < 22; ++divs ){
    int N = 10;
    double* crossValidationAverage = new double[N];
    for (int n = 0; n < N; ++n ){
      data.mixData();
      double* results = new double[divs];
      for( int i=0; i<divs; ++i ){
          Data l_set(data.getTestSet(i, divs));
          Tree classifier(&l_set);
          classifier.makeTree();
          TestData test_set(data.getLearningSet(i, divs));
          test_set.setClassifier(&classifier);
          test_set.classify();
          results[i] = test_set.checkEfficiency();
        }

        crossValidationAverage[n] = average(results, divs);

        delete [] results;
    }
    res << "Average accuracy for " << divs - 1 << " test sets and 1 learning set: \t" << average(crossValidationAverage, N) << "\n";
    delete[] crossValidationAverage;
  }

  res.close();
}
