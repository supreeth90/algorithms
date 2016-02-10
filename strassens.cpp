#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <sys/time.h>

using namespace std;
class Matrix {
	public:
		float **matrix;
		int row,col;

		Matrix(int row,int col);
		Matrix(float** mat, int n);
		void fillWithRandom();
		void display();

};

Matrix::Matrix(int row,int col) {
	matrix = new float*[row];
	for(int i = 0; i < row; ++i) {
    	matrix[i] = new float[col];
    }
	this->row=row;
	this->col=col;
}

Matrix::Matrix(float** mat, int n) {
	matrix=mat;
	this->row=n;
	this->col=n;
}

void Matrix::fillWithRandom() {
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			matrix[i][j]=rand()%1000;
		}
	}
}

void Matrix::display() {
	cout << "---------Printing the matrix-------" << endl;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cout << matrix[i][j] << "	";
		}
		cout << endl;
	}
}

Matrix *expandMatrix(Matrix *matrix1) {
	int numRows=pow(2,ceil( log2 (matrix1->row)));
	int numCols=pow(2,ceil( log2 (matrix1->col)));

	Matrix *matrix2=new Matrix(numRows,numCols);

	for(int i=0;i<numRows;i++) {
		for(int j=0;j<numCols;j++) {
			if(i<matrix1->row && j<matrix1->col) {
				matrix2->matrix[i][j]=matrix1->matrix[i][j];
			} else {
				matrix2->matrix[i][j]=0.0;
			}
		}
	}
	return matrix2;
}



Matrix *divideMatrix(Matrix *matrix1,int divideType) {
	Matrix *matrix3=new Matrix(matrix1->row/2,matrix1->row/2);
	int rowStart=0;
	int rowEnd=0;
	int colStart=0;
	int colEnd=0;
	int totalRows=matrix1->row;
	int totalCols=matrix1->col;

	if(divideType == 1 ) {
		colEnd=(totalCols/2)-1;
		rowEnd=(totalRows/2)-1;
	} else if(divideType == 2) {
		colStart=totalCols/2;
		colEnd=totalCols-1;
		rowEnd=(totalRows/2)-1;
	} else if(divideType == 3) {
		rowStart=totalRows/2;
		rowEnd=totalRows-1;
		colEnd=(totalCols/2)-1;
	} else {
		colStart=totalCols/2;
		colEnd=totalCols-1;
		rowStart=totalRows/2;
		rowEnd=totalRows-1;
	}


	if(rowEnd-rowStart+1 != matrix1->row/2) {
		cout << "Some error!!" << endl;
	}

	for(int i=rowStart;i<=rowEnd;i++) {
		for(int j=colStart;j<=colEnd;j++) {
			matrix3->matrix[i-rowStart][j-colStart]=matrix1->matrix[i][j];	
		}
	}
	return matrix3;
}

Matrix *combineMatrix(Matrix *matrix1,Matrix *matrix2,Matrix *matrix3,Matrix *matrix4) {
	Matrix *matrix5=new Matrix(matrix1->row*2,matrix1->col*2);
	for(int i=0;i<matrix1->row;i++) {
		for(int j=0;j<matrix1->col;j++) {
			matrix5->matrix[i][j]=matrix1->matrix[i][j];	
		}
	}
	for(int i=0;i<matrix2->row;i++) {
		for(int j=0;j<matrix2->col;j++) {
			matrix5->matrix[i][j+matrix1->col]=matrix2->matrix[i][j];	
		}
	}
	for(int i=0;i<matrix3->row;i++) {
		for(int j=0;j<matrix3->col;j++) {
			matrix5->matrix[i+matrix1->row][j]=matrix3->matrix[i][j];	
		}
	}
	for(int i=0;i<matrix4->row;i++) {
		for(int j=0;j<matrix4->col;j++) {
			matrix5->matrix[i+matrix4->row][j+matrix4->col]=matrix4->matrix[i][j];	
		}
	}
	return matrix5;
}

Matrix *matrixSubtract(Matrix *matrix1,Matrix *matrix2) {
	Matrix *matrix3=new Matrix(matrix1->row,matrix1->col);
	for(int i=0;i<matrix1->row;i++) {
		for(int j=0;j<matrix1->col;j++) {
			matrix3->matrix[i][j]=matrix1->matrix[i][j]-matrix2->matrix[i][j];	
		}
	}
	return matrix3;
}

Matrix *matrixAdd(Matrix *matrix1,Matrix *matrix2) {
	Matrix *matrix3=new Matrix(matrix1->row,matrix1->col);
	for(int i=0;i<matrix1->row;i++) {
		for(int j=0;j<matrix1->col;j++) {
			matrix3->matrix[i][j]=matrix1->matrix[i][j]+matrix2->matrix[i][j];	
		}
	}
	return matrix3;
}


Matrix* matrixMultiply(Matrix *matrix1,Matrix *matrix2) {
	int n=matrix1->row;
	
	Matrix *matrix3=new Matrix(n,n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			matrix3->matrix[i][j]=0;
			for(int k=0;k<n;k++) {
				matrix3->matrix[i][j]=matrix3->matrix[i][j]+matrix1->matrix[i][k]*matrix2->matrix[k][j];
			}
		}
	}
	return matrix3;
}

Matrix* StrassensR(Matrix *matrix1,Matrix *matrix2) {

	//Base case
	if(matrix1->row == 8) {
		return matrixMultiply(matrix1,matrix2);
	}


	Matrix *matrixA=divideMatrix(matrix1,1);
	Matrix *matrixB=divideMatrix(matrix1,2);
	Matrix *matrixC=divideMatrix(matrix1,3);
	Matrix *matrixD=divideMatrix(matrix1,4);

	Matrix *matrixE=divideMatrix(matrix2,1);
	Matrix *matrixF=divideMatrix(matrix2,2);
	Matrix *matrixG=divideMatrix(matrix2,3);
	Matrix *matrixH=divideMatrix(matrix2,4);

	Matrix *matrixP1=StrassensR(matrixA,matrixSubtract(matrixF,matrixH));
	Matrix *matrixP2=StrassensR(matrixAdd(matrixA,matrixB),matrixH);
	Matrix *matrixP3=StrassensR(matrixAdd(matrixC,matrixD),matrixE);
	Matrix *matrixP4=StrassensR(matrixD,matrixSubtract(matrixG,matrixE));
	Matrix *matrixP5=StrassensR(matrixAdd(matrixA,matrixD),matrixAdd(matrixE,matrixH));
	Matrix *matrixP6=StrassensR(matrixSubtract(matrixB,matrixD),matrixAdd(matrixG,matrixH));
	Matrix *matrixP7=StrassensR(matrixSubtract(matrixA,matrixC),matrixAdd(matrixE,matrixF));

	Matrix *matrixFinal1=matrixAdd(matrixSubtract(matrixAdd(matrixP4,matrixP5),matrixP2),matrixP6);
	Matrix *matrixFinal2=matrixAdd(matrixP1,matrixP2);
	Matrix *matrixFinal3=matrixAdd(matrixP3,matrixP4);
	Matrix *matrixFinal4=matrixSubtract(matrixSubtract(matrixAdd(matrixP1,matrixP5),matrixP3),matrixP7);


	return combineMatrix(matrixFinal1,matrixFinal2,matrixFinal3,matrixFinal4);

}

Matrix* StrassensSetup(Matrix *matrix1,Matrix *matrix2) {
	
	matrix1=expandMatrix(matrix1);
	matrix2=expandMatrix(matrix2);

	return StrassensR(matrix1,matrix2);

}

double calculateTimeDiff(struct timeval startTime,struct timeval endTime) {

	return ((endTime.tv_sec - startTime.tv_sec)*1000 + (endTime.tv_usec - startTime.tv_usec)/1000);


}

int main(int argc,char **argv) {
	struct timeval startTime,endTime;
	double timeDiff=0.0;
	
	// **** CHANGE THIS VALUE TO VARY THE NUM OF ROWS ****
	int nrow=32;

	Matrix *mat1=new Matrix(nrow,nrow);
	mat1->fillWithRandom();
	mat1->display();

	Matrix *mat2=new Matrix(nrow,nrow);
	mat2->fillWithRandom();
	mat2->display();
	
	gettimeofday(&startTime,NULL);
	Matrix *mat3=matrixMultiply(mat1,mat2);
	gettimeofday(&endTime,NULL);

	timeDiff=calculateTimeDiff(startTime,endTime);

	cout << "Running for "<< nrow << " rows" << endl;
	cout << "Running Time in Regular Multiplication :" << timeDiff << " ms" << endl;

	cout << "Result:" << endl;
	mat3->display();

	gettimeofday(&startTime,NULL);
	Matrix *mat4=StrassensSetup(mat1,mat2);
	gettimeofday(&endTime,NULL);

	timeDiff=calculateTimeDiff(startTime,endTime);
	cout << "Running Time in Strassens :" << timeDiff << " ms" << endl;

	cout << "Result:" << endl;
	mat4->display();
	
	return 1;
}