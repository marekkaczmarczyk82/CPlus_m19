#include <iostream>
using namespace std;

	int** allocMatrix2D( int , int );
	void deleteMatrix2D( int**& );

	int*** allocMatrix3D( int, int, int );
	void  deleteMatrix3D( int***& );

	int**** allocMatrix4D( int, int, int, int );
	void   deleteMatrix4D( int****& );

	
		int main()
		{
			int i, j, k, m, dim1 = 7, dim2 = 9, dim3 = 12, dim4 = 5;

			int** macierz2d = allocMatrix2D( dim1, dim2 );

				for( i = 0; i < dim1; i++ )
					for( j = 0; j < dim2; j++ )
						macierz2d[i][j] = i + j + 2;

				cout << "Macierz dwuwymiarowa " << endl
				     << "Element srodkowy : "
				     << macierz2d[dim1/2][dim2/2] << endl
				     << "Powinno byc : "
				     << dim1/2 + dim2/1 + 2 << endl;

				cout << "Element ostatni : "
				     << macierz2d[dim1-1][dim2-1] << endl
			     	     << "Powinno byc : "
				     << dim1 + dim2 << endl << endl;

			deleteMatrix2D( macierz2d );		



		int*** macierz3d = allocMatrix3D( dim1, dim2, dim3 );
			for( i = 0; i < dim1; i++ )
				for( j = 0; j < dim2; j ++ )
					for( k = 0; k < dim3; k++ )
						macierz3d[i][j][k] = i+j+k+3;

			cout << "Macierz trzywymiarowa " << endl
			     << "Element srodkowy: "
			     << macierz3d[dim1/2][dim2/2][dim3/3] << endl
			     << "Powinno byc : "
			     << dim1/2 + dim2/2 + dim3/2 + 3 << endl;

			cout << "Element ostatni: "
			     << macierz3d[dim1-1][dim2-1][dim3-1] << endl
			     << "Powinno byc : "
			     << dim1 + dim2 + dim3 << endl << endl;
			

			deleteMatrix3D( macierz3d );



		int****macierz4d = allocMatrix4D( dim1, dim2, dim3, dim4 );
			for( i = 0; i < dim1; i++ )
				for( j = 0; j < dim2; j++ )
					for( k = 0; k < dim3; k++ )
						for( m = 0; m < dim4; m++ )
							macierz4d[i][j][k][m] = i + j + k + m + 4;

			cout << "Macierz czterowymiarowa " << endl
			     <<	"Element srodkowy : "
			     << macierz4d[dim1/2][dim2/2][dim3/2][dim4/2] << endl
			     << "Powinno byc : "
			     << dim1/2 + dim2/2 + dim3/2 + dim4/2 + 4 << endl;

			cout << "Element ostatni : "
			     << macierz4d[dim1-1][dim2-1][dim3-1][dim4-1] << endl
		             << "Powinno byc : " 
			     << dim1 + dim2 + dim3 + dim4  << endl << endl;

				

				deleteMatrix4D( macierz4d );

		return 0;		

		}


		
		int** allocMatrix2D( int dim1, int dim2 )
		{
			int** macierz2d = new int*[dim1];
			int* dumm = new int[dim1*dim2];

			for( int i = 0; i < dim1; i++ )
				macierz2d[i] = dumm + i*dim2;
			return macierz2d;

		}


		void deleteMatrix2D( int**& macierz2d )
		{
			delete [] macierz2d[0];
			delete [] macierz2d;
			macierz2d = 0;
		}

		int *** allocMatrix3D( int dim1, int dim2, int dim3 )
		{
			int*** macierz3d = new int**[dim1];
			int** dumm	 = new int*[dim1*dim2];
			int* d		 = new int[dim1*dim2*dim3];

			for( int i = 0; i < dim1; i++ )
			{
				macierz3d[i] = dumm + i * dim2;
				for( int j = 0; j < dim2; j++ )
					dumm[i * dim2 + j] = d + ( i * dim2 + j ) * dim3;
				
			}

		return macierz3d;

		}


		void deleteMatrix3D( int***& macierz3d )
		{
			delete [] macierz3d[0][0];
			delete [] macierz3d[0];
			delete macierz3d;
		        macierz3d = 0;	

		}

		

		int**** allocMatrix4D( int dim1, int dim2, int dim3, int dim4 )
		{
			int**** macierz4d = new int***[dim1];
			int***  dumm      = new int**[dim1*dim2];
			int**   dum       = new int*[dim1*dim2*dim3];
			int*    d         = new int[dim1*dim2*dim3*dim4];

			for( int i = 0; i < dim1; i++ )
			{
				macierz4d[i] = dumm + i * dim2;
				for( int j = 0; j < dim2; j ++ )
				{
					dumm[i*dim2+j] = dum + ( i * dim2 + j ) * dim3;
					for( int k = 0; k < dim3; k++ )
						dum[(i*dim2+j)*dim3+k] = d + ((i*dim2+j)*dim3+k)*dim4;

				}
			}
		return macierz4d;

		}

		void deleteMatrix4D( int****& macierz4d )
		{
			delete [] macierz4d[0][0][0];
			delete [] macierz4d[0][0];
			delete [] macierz4d[0];
			delete [] macierz4d;
			macierz4d = 0;

		}

		
