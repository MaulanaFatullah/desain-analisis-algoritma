#include <iostream>

using namespace std;

int main()
{

  int numNodes;

  cout << "Masukkan jumlah kota: ";
  cin >> numNodes;

  int costMatrix[numNodes][numNodes];

  for (int i = 0; i < numNodes; i++)
  {
    cout << "Nilai cost matrix baris ke-: " << i + 1 << endl;
    for (int j = 0; j < numNodes; j++)
    {
      cin >> costMatrix[i][j];
    }
  }

  cout << "\nMatriks Biaya:" << endl;
  for (int i = 0; i < numNodes; i++)
  {
    for (int j = 0; j < numNodes; j++)
    {
      cout << costMatrix[i][j] << " ";
    }
    cout << endl;
  }

  int globalMinCost = INT_MAX;
  for (int i = 0; i < numNodes; i++)
  {
    int rowSum = 0;
    for (int j = 0; j < numNodes; j++)
    {
      rowSum += costMatrix[i][j];
    }
    globalMinCost = min(globalMinCost, rowSum);
  }

  cout << "Minimum Cost Keseluruhan: " << globalMinCost << endl;

  return 0;
}
