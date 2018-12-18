from collections import defaultdict
import heapq


def kodowanie(ilosc_znakow):
    sterta = [[ilosc, [znak, ' ']] for znak, ilosc in ilosc_znakow.items()]
    heapq.heapify(sterta)  # zmienia liste sterta na sterte
    while len(sterta) > 1:
        mini = heapq.heappop(sterta)  # zwraca najmniejszy element sterty nie zmieniając jej
        maxi = heapq.heappop(sterta)
        for el in mini[1:]:
            el[1] = '0' + el[1]
        for el in maxi[1:]:
            el[1] = '1' + el[1]
        heapq.heappush(sterta, [mini[0] + maxi[0]] + mini[1:] + maxi[1:])  # odkladanie elementu na stercie
    return sorted(heapq.heappop(sterta)[1:], key=lambda a: (len(a[-1]), a))


tresc_do_kodowania = input("Wpisz teskt do zakodowania")
ilosc_znakow = defaultdict(int)
for symbol in tresc_do_kodowania:
    ilosc_znakow[symbol] += 1
huffmann = kodowanie(ilosc_znakow)
for a in huffmann:
    print(a[0].ljust(10) + str(ilosc_znakow[a[0]]).ljust(10) + a[1])
