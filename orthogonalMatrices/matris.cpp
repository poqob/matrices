#include <iostream>
using namespace std;

class OrthogonalMatrice
{
public:
    // fields
    int *row, *column;
    // defining matrice.
    int **matrice;
    // copy
    int **copyMatrice(int **matrice2, int *height)
    {
        // TODO: matrix cleaner will be coded.
        int **copyM = new int *[*height];

        for (int i = 0; i < *height; i++)
            copyM[i] = new int[*height];

        for (int i = 0; i < *height; i++)
        {
            for (int j = 0; j < *height; j++)
            {
                copyM[i][j] = matrice2[i][j];
            }
        }

        return copyM;
    }

    // creating matrice
    void creatingMatrice()
    {
        matrice = new int *[*row];
        for (int i = 0; i < *row; i++)
            matrice[i] = new int[*row];

        for (int i = 0; i < *row; i++)
        {
            for (int j = 0; j < *column; j++)
            {
                cout << i + 1 << ". row " << j + 1 << ". column: ";
                cin >> matrice[i][j];
            }
        }
        cout << endl;
    }

    // write the matrice.
    void writeMatrice(int **mat)
    {
        // write matrice.
        for (int i = 0; i < *row; i++)
        {
            for (int j = 0; j < *column; j++)
            {
                cout << mat[i][j] << "   ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // returs a matrice that is upper triangle matrice of **mat parameters.
    int **upperTriangleMatrice(int **mat, int *height)
    {
        int **upperTriangleM = copyMatrice(mat, height);

        for (int i = 0; i < *height; i++)
        {
            for (int j = 0; j < i; j++)
            {
                upperTriangleM[i][j] = 0;
            }
        }

        return upperTriangleM;
    }
    // returs a matrice that is lower triangle matrice of **mat parameters.
    int **lowerTriangleMatrice(int **mat, int *height)
    {
        int **lowerTriangleM = copyMatrice(mat, height);

        for (int i = 0; i < *height; i++)
        {
            for (int j = *height; j >= i; j--)
            {
                lowerTriangleM[i][j] = 0;
            }
        }

        return lowerTriangleM;
    }

    // creates zero matrice.
    int **zeros(int *height, int *width)
    {
        int **zerosM = 0;
        zerosM = new int *[*height];
        for (int i = 0; i < *height; i++)
        {
            zerosM[i] = new int[*width];
            for (int j = 0; j < *width; j++)
            {
                zerosM[i][j] = 0;
            }
        }
        return zerosM;
    }
    // creates matrice with only value one.
    int **ones(int *height, int *width)
    {
        int **onesM = 0;
        onesM = new int *[*height];
        for (int i = 0; i < *height; i++)
        {
            onesM[i] = new int[*width];
            for (int j = 0; j < *width; j++)
            {
                onesM[i][j] = 1;
            }
        }
        return onesM;
    }

    // the method to sum two matrices
    int **sumOftwoMatrice(int **matrice1, int **matrice2, int *height)
    {
        int **mat = new int *[*height];
        for (int i = 0; i < *height; i++)
        {
            mat[i] = new int[*height];
            for (int j = 0; j < *height; j++)
            {
                mat[i][j] = matrice1[i][j] + matrice2[i][j];
            }
        }
        return mat;
    }
    // TODO:i think we can take more argumans with int args.
    // TODO:i will be better if i convert that method to an operator (+).

    // constructor that needs row and col. num to generate new matrice.
    OrthogonalMatrice(int *r)
    {
        row = r;
        column = row;
        // to create new matrice.
        creatingMatrice();
        cout << ":the matrice:" << endl;
        writeMatrice(matrice);
        int **ut = upperTriangleMatrice(matrice, row);
        int **lt = lowerTriangleMatrice(matrice, row);
        int **sum = sumOftwoMatrice(ut, lt, row);
        // writeMatrice(zeros(row, column));
        cout << ":upper triangle of matrice:" << endl;
        writeMatrice(ut);
        cout << ":lower triangle of matrice:" << endl;
        writeMatrice(lt);
        cout << ":sum of triangels:" << endl;
        writeMatrice(sum);
    }

    // constructor, that only allows matrice form.
    OrthogonalMatrice(int **matrice)
    {
        matrice = this->matrice;
    }

    ~OrthogonalMatrice()
    {
    }
    // TODO: garbage management will be coded.
};

int main()
{

    int r;
    cout << "enter matrice scale: ";
    cin >> r;
    cout << endl;
    OrthogonalMatrice *m = new OrthogonalMatrice(&r);

    // int **m;
    // Matrice *m=new Matrice(m);

    // int **a = new int *[3];
    // Matrice *m = new Matrice(a);

    system("PAUSE");
    return 0;
}
