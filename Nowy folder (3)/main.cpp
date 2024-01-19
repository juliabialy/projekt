#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout << endl;
    cout << "1. Dodaj element tablicy" << endl;
    cout << "2. Wstaw element tablicy" << endl;
    cout << "3. Usun element tablicy" << endl;
    cout << "4. Wyswietl elementy tablicy" << endl;
    cout << "5. Zapisz do pliku" << endl;
    cout << "6. Wczytaj z pliku" << endl;
    cout << "7. Zamknij program" << endl;
    cin >> x;
    cout << endl;
    return x;
}

void DodajElement(int *&p, int &n)
{
    int *tmp = new int[n + 1];

    if (p != nullptr)
    {
        for (int i = 0; i < n; i++)
        {
            tmp[i] = p[i];
        }
        delete[] p;
    }

    cout << "Podaj wartosc elementu tablicy: ";
    cin >> tmp[n];
    p = tmp;
    n++;
}

void WyswietlElementy(int *p, int n)
{
    cout << "Zawartosc tablicy:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << ", ";
    }
    cout << endl;
}

void WstawElement(int *&p, int &n)
{
    int indeks;

    if (n == 0)
    {
        cout << "Tablica jest pusta" << endl;
        return;
    }

    cout << "Podaj indeks, na ktory chcesz wstawic element: ";
    cin >> indeks;

    if (indeks < 0 || indeks >= n)
    {
        cout << "Zly indeks" << endl;
        return;
    }

    int *tmp = new int[n + 1];

    for (int i = 0; i < indeks; i++)
    {
        tmp[i] = p[i];
    }

    cout << "Podaj wartosc elementu do wstawienia: ";
    cin >> tmp[indeks];

    for (int i = indeks + 1; i < n + 1; i++)
    {
        tmp[i] = p[i - 1];
    }

    delete[] p;
    p = tmp;
    n++;
}

void UsunElement(int *&p, int &n)
{
    int indeks;

    if (n == 0)
    {
        cout << "Tablica jest pusta" << endl;
        return;
    }

    cout << "Podaj indeks elementu, ktory chcesz usunac: ";
    cin >> indeks;

    if (indeks < 0 || indeks >= n)
    {
        cout << "Nieprawidlowy indeks" << endl;
        return;
    }

    int *tmp = new int[n - 1];

    for (int i = 0; i < indeks; i++)
    {
        tmp[i] = p[i];
    }

    for (int i = indeks + 1; i < n; i++)
    {
        tmp[i - 1] = p[i];
    }

    delete[] p;
    p = tmp;
    n--;
}

void ZapiszDoPliku(int *p, int n, const string &nazwaPliku)
{
    ofstream plik(nazwaPliku);

    if (plik.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            plik << p[i] << " ";
        }
        plik.close();
        cout << "Zapisano do pliku: " << nazwaPliku << endl;
    }
    else
    {
        cout << "Nie mozna otworzyc pliku do zapisu" << endl;
    }
}

void WczytajZPliku(int *&p, int &n, const string &nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (plik.is_open())
    {
   
        plik >> n;

        int *tmp = new int[n];

        for (int i = 0; i < n; i++)
        {
            plik >> tmp[i];
        }

        plik.close();

        delete[] p;


        p = tmp;

        cout << "Wczytano z pliku: " << nazwaPliku << endl;
    }
    else
    {
        cout << "Nie mozna otworzyc pliku do wczytania" << endl;
    }
}

int main()
{
    int m;
    int *p = nullptr;
    int n = 0;

    while (true)
    {
        m = Menu();

        switch (m)
        {
        case 7:
        {
            delete[] p;
            return 0;
        }
        case 1:
        {
            DodajElement(p, n);
            break;
        }
        case 2:
        {
            WstawElement(p, n);
            break;
        }
        case 3:
        {
            UsunElement(p, n);
            break;
        }
        case 4:
        {
            WyswietlElementy(p, n);
            break;
        }
        case 5:
        {
            ZapiszDoPliku(p, n, "tablica.txt");
            break;
        }
        case 6:
        {
            WczytajZPliku(p, n, "tablica.txt");
            break;
        }
        case 8:
        {
  
            delete[] p;
            return 0;
        }
        default:
        {
            cout << "Nieprawidlowa opcja" << endl;
        }
        }
    }

    return 0;
}
