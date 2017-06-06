Jêzyk skryptowy do Mario

Jêzyk skryptowy do Mario. Po wielu trudach Twoja implemenatcja gry Mario jest skoñczona. Jednak nie jesteœ do koñca zadowolony - w grze brakuje mo¿liwoœci zawansowanego ustawiania parametrów. Okazuje siê, ¿e rozwi¹zanie tego problemu kryje siê w jêzykach skryptowych.
Jako ambitny student wydzia³u ETI postanowi³eœ napisaæ swój w³asny jêzyk skryptowy.
Jêzyk ten bêdzie zawiera³ zmienne odpowiadaj¹ce w jêzyku C zmiennym typu int. Wszystkie zmienne s¹ globalne i nie trzeba ich deklarowaæ. Ka¿da zmienna mo¿e mieæ wartoœæ bêd¹c¹ liczb¹ ca³kowit¹ (odpowiadaj¹c¹ typowi int) lub wartoœæ specjaln¹ Nul. Watroœæ Nul jest domyœln¹ wartoœci¹ zmiennej. Zmienne s¹ reprezentowane jako ci¹g liter alfabetu ³aciñskiego, wielkoœæ liter ma znaczenie.
Operatory arytmetyczne dwuargumentowe = == < > <= >= + - / * % i operator arytmetyczny jednoargumentowy - dzia³aj¹ jak w jêzyku C. Jeœli któryœ z argumentów ma wartoœæ Nul, to wynikiem operacji jest tak¿e Nul. W jêzyku wystêpuj¹ tak¿e operatory logiczne koniunkcji &, alternatywy | i negacji !. Wartoœci logicznej fa³sz odpowiada wartoœæ Nul, a wartoœci logicznej prawda jakakolwiek inna wartoœæ. Operatory logiczne jako prawdê zwracaj¹ wartoœæ 0.
Wszystkie operatory dwuargumentowe oprócz = s¹ lewostronnie domkniête. Kolejnoœæ priorytetów operatorów, od najmniejszego priorytetu, to: 
= | & (!= ==) (< > <= >=) (+ -) (/ * %) (! -u)
operatory o tym samym priorytecie zosta³y zgrupowane nawiasem; -u to operator jednoargumentowy.
Instrukcja warunkowa bêdzie realizowana przez operator ?. Instukcja pêtli bêdzie realizowana jako while przy u¿yciu operatora @.
?(warunek) {kod}
@(warunek) {kod}
W opisanych instrukcjach musz¹ wystêpowaæ nawiasy okr¹g³e i klamrowe.
Jednoczeœnie chcemy stworzyæ ograniczenie na liczbê wykonywanych instrukcji. Realizacj¹ tego zadania bêdzie licznik wykonanych operacji. Ka¿de wykonanie operatora i ka¿de sprawdzenie warunku w instrukcji warunkowej i w pêtli powoduje inkrementacjê tego licznika.
Program koñczy siê po ostatniej instrukcji kodu lub po przekroczeniu zadanej wartoœci przez licznik operacji.
Uwaga: a=-10 oznacza do zmiennej a przypisz liczbê -10, a nie na liczbie 10 wykonaj operacjê unarn¹ - i zapisz do zmiennej a.
Uwaga: operatory arytmetyczne dla wartoœci liczbowych zachowuj¹ siê tak samo jak ich opowiedniki w jêzyku C++.
Uwaga: nie mo¿na korzystaæ z STL'a ani z klasy string.
Wejœcie

W pierwszej linii znajduje siê liczba ograniczaj¹ca licznik operacji.
W drugiej linii znajduje siê lista zmiennych, których wartoœci nale¿y wyœwietliæ po zakoñczeniu programu.
W kolejnych liniach znajduje siê kod programu.
W ka¿dej linii jest co najwy¿ej 1000 znaków.
Wyjœcie

W pierwszej linii wypisujemy wartoœæ licznika operacji, a w kolejnych liniach nazwy oraz wartoœci zmiennych, które wyst¹pi³y w drugiej linii danych wejœciowych.