void rotate(char matrix[10][10])
{
  char new[10][10];
  for(int i=0; i<10; i++)
    {
      for (int j=0; j<10; j++)
	{
	  new[i][j]= matrix[j][i];
	}
    }

  for(int i=0; i<10; i++)
    {
      int k=0;
      for(int j=9; j>=0; j--)
	{
	  matrix[i][k]= new[i][j];
	  k++;}
    }
}
