J�zyk skryptowy do Mario

J�zyk skryptowy do Mario. Po wielu trudach Twoja implemenatcja gry Mario jest sko�czona. Jednak nie jeste� do ko�ca zadowolony - w grze brakuje mo�liwo�ci zawansowanego ustawiania parametr�w. Okazuje si�, �e rozwi�zanie tego problemu kryje si� w j�zykach skryptowych.
Jako ambitny student wydzia�u ETI postanowi�e� napisa� sw�j w�asny j�zyk skryptowy.
J�zyk ten b�dzie zawiera� zmienne odpowiadaj�ce w j�zyku C zmiennym typu int. Wszystkie zmienne s� globalne i nie trzeba ich deklarowa�. Ka�da zmienna mo�e mie� warto�� b�d�c� liczb� ca�kowit� (odpowiadaj�c� typowi int) lub warto�� specjaln� Nul. Watro�� Nul jest domy�ln� warto�ci� zmiennej. Zmienne s� reprezentowane jako ci�g liter alfabetu �aci�skiego, wielko�� liter ma znaczenie.
Operatory arytmetyczne dwuargumentowe = == < > <= >= + - / * % i operator arytmetyczny jednoargumentowy - dzia�aj� jak w j�zyku C. Je�li kt�ry� z argument�w ma warto�� Nul, to wynikiem operacji jest tak�e Nul. W j�zyku wyst�puj� tak�e operatory logiczne koniunkcji &, alternatywy | i negacji !. Warto�ci logicznej fa�sz odpowiada warto�� Nul, a warto�ci logicznej prawda jakakolwiek inna warto��. Operatory logiczne jako prawd� zwracaj� warto�� 0.
Wszystkie operatory dwuargumentowe opr�cz = s� lewostronnie domkni�te. Kolejno�� priorytet�w operator�w, od najmniejszego priorytetu, to: 
= | & (!= ==) (< > <= >=) (+ -) (/ * %) (! -u)
operatory o tym samym priorytecie zosta�y zgrupowane nawiasem; -u to operator jednoargumentowy.
Instrukcja warunkowa b�dzie realizowana przez operator ?. Instukcja p�tli b�dzie realizowana jako while przy u�yciu operatora @.
?(warunek) {kod}
@(warunek) {kod}
W opisanych instrukcjach musz� wyst�powa� nawiasy okr�g�e i klamrowe.
Jednocze�nie chcemy stworzy� ograniczenie na liczb� wykonywanych instrukcji. Realizacj� tego zadania b�dzie licznik wykonanych operacji. Ka�de wykonanie operatora i ka�de sprawdzenie warunku w instrukcji warunkowej i w p�tli powoduje inkrementacj� tego licznika.
Program ko�czy si� po ostatniej instrukcji kodu lub po przekroczeniu zadanej warto�ci przez licznik operacji.
Uwaga: a=-10 oznacza do zmiennej a przypisz liczb� -10, a nie na liczbie 10 wykonaj operacj� unarn� - i zapisz do zmiennej a.
Uwaga: operatory arytmetyczne dla warto�ci liczbowych zachowuj� si� tak samo jak ich opowiedniki w j�zyku C++.
Uwaga: nie mo�na korzysta� z STL'a ani z klasy string.
Wej�cie

W pierwszej linii znajduje si� liczba ograniczaj�ca licznik operacji.
W drugiej linii znajduje si� lista zmiennych, kt�rych warto�ci nale�y wy�wietli� po zako�czeniu programu.
W kolejnych liniach znajduje si� kod programu.
W ka�dej linii jest co najwy�ej 1000 znak�w.
Wyj�cie

W pierwszej linii wypisujemy warto�� licznika operacji, a w kolejnych liniach nazwy oraz warto�ci zmiennych, kt�re wyst�pi�y w drugiej linii danych wej�ciowych.