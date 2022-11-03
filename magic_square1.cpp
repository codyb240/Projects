#include"magic_square.h"

MagicSquare::MagicSquare()
{
 for(int i = 0; i < MAX_SIZE; i++)
 {
  for(int j = 0; j < MAX_SIZE; j++)
  {
   magic[i][j] = 0;                  // Initialize array to zero, or empty.
  }
 }
 magic_constant = 0;		     // Initialize magic_constant to zero.
 size = 0;			     // Initialize size to zero.
}
//--------------------------------------------------------------------------
MagicSquare::MagicSquare(int square_size)
{
 size = square_size;         // Set size;

 for(int i = 0; i < size; i++)
 {
  for(int j = 0; j < size; j++)
  {
   magic[i][j] = 0;                  // Initialize array to zero, or empty.
  }
 }
 magic_constant = 0;		     // Initialize magic_constant to zero.
}
//--------------------------------------------------------------------------
bool MagicSquare::analyze_square()
{
    int FirstSum = 0, SecondSum=0;

    
    for (int i = 0; i < size; i++) 
        FirstSum = FirstSum + magic[i][i];  //find first diagonal sum

    for (int i = 0; i < size; i++) 
        SecondSum = SecondSum + magic[i][size - 1 - i]; //find second diagonal sum
    
     if(FirstSum != SecondSum)  
        return 0; //Check whether the two diagonal sums are the same
  
     for (int i = 0; i < size; i++){ 
          
        int SumRow = 0;

        for (int j = 0; j < size; j++) 
            SumRow = SumRow + magic[i][j]; //find sum of the rows
          
        if (SumRow != FirstSum) 
            return 0; //Check if the row of the sums are equal to the diagonal sums
    } 
  
    for (int i = 0; i < size; i++){ 
          
        int SumColumn = 0;  

        for (int j = 0; j < size; j++){
		
            SumColumn += magic[j][i]; //find sum of columns
  		}

        if (SumColumn != FirstSum)  
            return 1; //Check if the row of the columns are equal to the diagonal sums
    } 
  	magic_constant = FirstSum;     // Compute magic_constant
    return true;
}
//---------------------------------------------------------------------------
void MagicSquare::is_magic()
{
 if( analyze_square() )		// If analise_square returns true, print this.
 {
  printf("\nThis is a Magic Square of sum %d.\n", magic_constant);
 }
 else				// Else print message and call generate_square
 {
  printf("\nThis is NOT a magic square. It should be:\n");
  generate_square();
  print_square(); 		// Print square.
 }
}
//-----------------------------------------------------------------------------
void MagicSquare::generate_square()
{
 int num = 1;	       // Number element in the square.
 
 int nn= (size*3) / 2; // This formula gets how many possible positions a 
                       // magic square can be started according to its
                       // dimensions. Ex: if size = 3, then you have 4 
                       // positions to start the square with number 1.
        
 for(int i = 0; i < size; i++)     // Starting row 0
   for(int j = 0; j < size; j++)   // Starting col 0
   {
    magic[(2*i-j+size)%size][(j-i+nn)%size]=num++;
    // Row position is computed by:
    // (2 * row_count - col_count + square_dimension) % square_dimension
    // Column position is computer by:
    // (row_count - column_count + possible_starts) % square_dimension
    // Then,
    // increment num.
  }
}
//----------------------------------------------------------------------------
void MagicSquare::read_data()
{
 do
 {
  printf("Enter size of square: ");
  scanf("%d", &size);			// Enter size of square.
 }while( size%2 == 0 || size < 3 || size > 9);
 					// Odd number, 3 <= size <= 9.

 printf("Enter square by row and 1 space\n");
 
 int i, j;
 for(i = 0; i < size; i++)
 {
  printf("-> ");
  for(j = 0; j < size; j++)
  { 
   scanf("%d", &magic[i][j]);		// Enter row by row.
  }
 }
}
//----------------------------------------------------------------------------
void MagicSquare::print_square()
{
 for(int i = 0; i < size; i++)
 {
  for(int j = 0; j < size; j++)
  {
   printf("%3d", magic[i][j]);		// Print square.
  }
  printf("\n");
 }
}
//---------------------------------------------------------------------------
