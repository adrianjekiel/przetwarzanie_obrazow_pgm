# przetwarzanie_obrazow_pgm

Template projektu z dummy plikami, posiada generycznego CMake'a do kompilowania projektów, pozwala również na pisanie i kompilowanie testów

Aby rozpocząć użytkowanie i pisanie kodu :

1. Stwórz folder workspace (gdziekolwiek)
2. Wejdź do folderu i Otwórz terminal w tym miejscu (prawy przycisk myszy i "open in terminal")
3. wpisz w terminalu: git clone https://github.com/adrianjekiel/przetwarzanie_obrazow_pgm.git -> sklonuje repozytorium
4. cd przetwarzanie_obrazow_pgm (przechodzi do folderu, cd .. przechodzi do folderu wcześniej)
5. z poziomu przetwarzanie_obrazow_pgm wpisując w terminalu można osiągnąć następujące wyniki względem kodu i repozytorium : 

    ./compilator.sh configure --> konfiguruje CMake'a, tworzy folder build, pobiera GTest, GMock, niezbędne do wykonania minimum raz
    
    ./compilator.sh rebuild ---> kompiluje caly projekt, wymaga wcześniej wykonania opcji configure minimum jeden raz
    
    ./compilator.sh clean ---> usuwa skompilowane pliki, po tej operacji mozna przebudowac od nowa cały projekt, nie tylko zmienione pliki
    
    ./compilator.sh ut ---> kompiluje testy i wykonuje je
    
    ./compilator.sh remove ---> usuwa folder build i konfiguracje CMake'a
6. have fun z programowaniem :D 


Praca z QTCreator Ubuntu 18.04
1. sudo apt install qtcreator   --> to pobierze QTcreatora
2. Po uruchomieniu wybierz "New Project"
3. Wybierz Import Existing Project
4. Nazwij go jakos xD
5. Jako Location ustaw folder z plikami z repozytorium (np workspace/przetwarzanie_obrazow_pgm)
6. Zaznacz pliki które chcesz mieć widoczne (mogą być wszystkie z folderu src i test oraz CMakeLists.txt)
7. Next i finish

integrowanie pliku compilator.sh z programem QTCreator
1. zakładka Projects
2. Build steps -> nacisnij krzyżyk (usunie aktualną defaultowa konfiguracje) -> add build step -> custom process step -> 
    command: browse i wybierz compilator.sh, arguments: configure, kliknij rename i zmien nazwe na konfigure
3. kliknij Add -> Clone Selected -> wpisz nazwe rebuild -> BuildSteps -> arguments: rebuild
4. kliknij Add -> Clone Selected -> wpisz nazwe clean -> BuildSteps -> arguments: clean
5. kliknij Add -> Clone Selected -> wpisz nazwe ut -> BuildSteps -> arguments: ut
6. kliknij Add -> Clone Selected -> wpisz nazwe remove -> BuildSteps -> arguments: remove

Następnie po lewej stronie nad przyciskami "mloteczka i playów" będziesz mógł wybierać którą opcję kompilowania chcesz wybrać jednym kliknięciem
po wybraniu opcji przyciśnij play lub F5 w zakładce compile output będzie pluło informacjami
