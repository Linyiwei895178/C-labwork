//Bubble Sort
template <class T>
void mySwap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void bubbleSort(T a[], int n)
{
    int i = n - 1;
    while (i > 0) {
        int lastExchange = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j+1] < a[j]) {
                mySwap(a[j], a[j + 1]);
                lastExchange = j;
            }
        }
        i =  lastExchange;
    }
}

//insert sort
template <class T>
void insertionSort(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        T temp = a[i];
        int j = i;
        while (j > 0 && temp < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;
    }
}

//selection sort
template <class T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int least = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[least])
            least = j;
        }
        mySwap(a[i], a[least]);
    }
}

template <class T>
int binSearch(const T list[], int n, const T &key)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == list[mid]) return mid;
        else if (key < list[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}