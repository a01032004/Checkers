# Checkers
Checkers tpro
# Долгосрочное домашнее задание (игра "Шашки")

## Этап I
Время на этап: **18 часов**

### Цель

Необходимо разработать игру для одного пользователя против компьютера. Правила для различных вариантов игры можно найти в интернете (например, в Википедии) и ниже в ТЗ.

### Задание

На этом этапе необходимо реализовать desktop-приложение c графической отрисовкой процесса игры и реализацией основной логики игры.

#### Функционал, который должен быть реализован:
1. Игровое меню
    * кнопка **Начать** - открывает новое окно с настройками игры:
        * выбор **количества раундов** или **быструю игру (1 раунд)**
        * выбор **варианта игры**: русские, обратные русские (поддавки), английские (чекерс), международные
        * выбор **цвета** шашек, за которые играет пользователь
        * кнопка "Начать игру"
    * кнопка **Настройки** - открывает новое окно с настройками:
        * выбором **имени** игрока
        * выбором **оформления** доски и шашек
        * кнопка "Сохранить" сохраняет настройки и выходит в предыдущее меню
    * кнопка **Выход** - выдаёт диалоговое окно "Хотите выйти из игры?" с вариантами действий по выходу из игры или возврату в игру.   
2. Игровой процесс
    * отрисовка доски и фигур на экране, выделение фигуры (рамки вокруг фигуры) после нажатия на неё, выделение доступных клеток для совершения хода (реализация одного из правил игры), перемещения фигур на доступные для хода клетки
    * удаление фигуры с доски после успешного хода противника (реализация одного из правил игры)
    * реализация фигуры "Дамка"
    * реализация алгоритма поведения бота-противника (компьютера)
    * реализация алгоритма определения конца игры
    * запрос статистики  и её визуализация
    * возможность поставить игру на паузу с отображением **диалогового окна**:                             /////////////************////////////
        * кнопка **Возобновить игру**
        * кнопка **Выйти из игры** - возврат в основное меню программы
        * кнопка **Рестарт** - запуск игры заново с теми же параметрами
    * визуальная часть:
        * отображение **времени** игры
        * отображение **счёта** игры (если это многораундовая игра)
        * отображение **счётчика раундов** (если это многораундовая игра)
        * отображение **имени** игрока                                                                            
    * по завершении игры вывод **диалогового окна**:                                                      
        * **имя** победителя
        * **счёт игры**, если это игра с несколькими раундами
        * кнопки **Выход** или **Рестарт**
    * логика игры:
        * **Базовые правила для всех вариантов игры:**
            - Все шашки, участвующие в партии, выставляются перед началом игры на доску. Далее они передвигаются по полям доски и могут быть сняты с неё в случае боя шашкой противника.
            - Брать шашку, находящуюся под боем, обязательно.
            - Существует только два вида шашек: простые и дамки. В начале партии все шашки простые. Простая шашка может превратиться в дамку, если она достигнет последнего противоположного горизонтального ряда доски (дамочного поля).
            - Простые шашки ходят только по направлению вперёд на следующее поле. Дамки могут ходить и вперёд и назад.
            - Игрок проигрывает, если остается без шашек или все его шашки оказываются **заперты**
            - В дополнение к базовым правилам у каждого варианта игры есть свои особенности (см. далее).
        * **Русские шашки:**
            * Шашки ходят только по клеткам тёмного цвета.
            * Доска расположена так, чтобы угловое поле внизу слева со стороны игрока было тёмным.
            * Простая шашка бьёт вперёд и назад, дамка ходит и бьёт на любое поле диагонали.
            * Во время боя простая шашка может превратиться в дамку и сразу продолжить бой по правилам дамки.
            * При наличии нескольких вариантов боя можно выбрать любой из них.

