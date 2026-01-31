#!/bin/bash

ROUGE='\033[0;31m'
VERT='\033[0;32m'
JAUNE='\033[1;33m'
NC='\033[0m'

SUCCESS=1

ARG1="3 2 a";
ARG2="3 2 2";

ARG3="3 2 2147483648";
ARG4="3 2 -2147483649";
ARG5="5 4 3 2 1";

ARG6="42";
ARG7="2 3";
ARG8="0 1 2 3";
ARG9="0 1 2 3 4 5 6 7 8 9";

ARG10="3 2 1";
ARG11="1 3 2";
ARG12="2 3 1";

ARG13="5 4 3 2 1";
ARG14="1 2 4 3 5";
ARG15="3 2 5 4 1";

ARG16="5 4 3 2 1";
ARG17="1 2 3 4 5";

format_checker_result() {
    local resultat="$1"

    case "$resultat" in
        *OK*)
            echo "${VERT}OK${NC}"
            ;;
        *KO*)
            echo "${ROUGE}KO${NC}"
            SUCCESS=0
            ;;
        *)
            echo ""
            ;;
    esac
}

cleanup() {
    echo "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    echo "++++++++++++++++++++++++++++ CLEAN UP +++++++++++++++++++++++++";
    echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    make fclean && rm shuffle**.txt;
}

trap cleanup EXIT

echo "Quel checker voulez-vous utiliser ?"
echo "(1) Notre checker"
echo "(2) Checker_linux"

read -p "Choix (1-2): " choix

case $choix in
    1)
        checker="./checker"
        ;;
    2)  
        checker="./checker_linux"
        ;;
    *)
        echo "Choix invalide, utilisation de NOTRE checker"
        checker="./checker"
        ;;
esac

shuf -i 1-500 -n 100 > shuffle_numbers.txt;
shuf -i 1-200 -n 50 > shuffle_numbers2.txt;
shuf -i 1-1000 -n 500 > shuffle_numbers3.txt;

# echo "\n+++++++++++++ NORMINETTE +++++++++++++\n";
# norminette;
echo "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
echo "++++++++++++++++++++++++++++ COMPILE ++++++++++++++++++++++++++";
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
make re && make bonus;


echo "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
echo "++++++++++++++++++++++++++ TEST ENTREE ++++++++++++++++++++++++";
echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

echo "\n============= ./push_swap \"$ARG1\" =============\n";
echo "Output: \c"; ./push_swap $ARG1; echo "Valgrind: \c";

valgrind ./push_swap $ARG1 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || echo "KO"

echo "\n============= ./push_swap \"$ARG1\" =============\n";
echo "Output: \c"; ./push_swap $ARG1; echo "Valgrind: \c";

valgrind ./push_swap $ARG1 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG2\" =============\n";
echo "Output: \c"; ./push_swap $ARG2; echo "Valgrind: \c";

valgrind ./push_swap $ARG2 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG3\" =============\n";
echo "Output: \c"; ./push_swap $ARG3; echo "Valgrind: \c";

valgrind ./push_swap $ARG3 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG4\" =============\n";
echo "Output: \c"; ./push_swap $ARG4; echo "Valgrind: \c";

valgrind ./push_swap $ARG4 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --simple \"$ARG5\" =============\n";
echo "Checker output: \c";

res=$(./push_swap --simple "$ARG5" | "$checker" "$ARG5")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG5 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --medium \"$ARG5\" =============\n";
echo "Checker output: \c";

res=$(./push_swap --medium "$ARG5" | "$checker" "$ARG5")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --medium $ARG5 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --complex \"$ARG5\" =============\n";
echo "Checker output: \c";

res=$(./push_swap --complex "$ARG5" | "$checker" "$ARG5")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --complex $ARG5 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --adaptive \"$ARG5\" =============\n";
echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG5" | "$checker" "$ARG5")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --adaptive $ARG5 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG5\" =============\n";
./push_swap --bench $ARG5 2>&1 | grep "strategy:"
echo "Checker output: \c"; 

echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG5" | "$checker" "$ARG5")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $ARG5 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG6\" =============\n";
echo "Output: "; ./push_swap $ARG6; echo "Valgrind: \c";

valgrind ./push_swap $ARG6 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG7\" =============\n";
echo "Output: "; ./push_swap $ARG7; echo "Valgrind: \c";

valgrind ./push_swap $ARG7 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG8\" =============\n";
echo "Output: "; ./push_swap $ARG8; echo "Valgrind: \c";

valgrind ./push_swap $ARG8 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG9\" =============\n";
echo "Output: "; ./push_swap $ARG9; echo "Valgrind: \c";

valgrind ./push_swap $ARG9 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG10\" =============\n";
./push_swap --bench $ARG10 2>&1 | grep "total_ops"
echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG10" | "$checker" "$ARG10")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $ARG10 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG11\" =============\n";
./push_swap --bench $ARG11 2>&1 | grep "total_ops"
echo "Checker output: \c"; ./push_swap --adaptive $ARG11 | $checker $ARG11; echo "Valgrind: \c";

echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG11" | "$checker" "$ARG11")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $ARG11 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG12\" =============\n";
./push_swap --bench $ARG12 2>&1 | grep "total_ops"
echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG12" | "$checker" "$ARG12")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $ARG12 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG13\" =============\n";
./push_swap --bench --simple $ARG13 2>&1 | grep "total_ops"
echo "Checker output: \c";

res=$(./push_swap --adaptive "$ARG13" | "$checker" "$ARG13")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG13 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG14\" =============\n";
./push_swap --bench --simple $ARG14 2>&1 | grep "total_ops"
echo "Checker output: \c"; 

res=$(./push_swap --adaptive "$ARG14" | "$checker" "$ARG14")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG14 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG15\" =============\n";
./push_swap --bench --simple $ARG15 2>&1 | grep "total_ops"
echo "Checker output: \c"; 

res=$(./push_swap --adaptive "$ARG15" | "$checker" "$ARG15")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG15 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }

echo "\n============= ./push_swap --bench --simple \"$ARG16\" =============\n";
./push_swap --bench --simple $ARG16 2>/dev/null
echo "Checker output: \c"; 

res=$(./push_swap --simple "$ARG16" | "$checker" "$ARG16")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG16 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --bench --simple \"$ARG16\" =============\n";
./push_swap --bench --simple $ARG16 1>/dev/null
echo "Checker output: \c";

res=$(./push_swap --simple "$ARG16" | "$checker" "$ARG16")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG16 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG16\" =============\n";
./push_swap --bench --simple $ARG16 2>&1 | grep "disorder"
echo "Checker output: \c"; ./push_swap --simple $ARG16 | $checker $ARG16;

res=$(./push_swap --simple "$ARG16" | "$checker" "$ARG16")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG16 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"$ARG17\" =============\n";
./push_swap --bench --simple $ARG17 2>&1 | grep "disorder"
echo "Checker output: \c"; 

res=$(./push_swap --simple "$ARG17" | "$checker" "$ARG17")
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $ARG17 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap \"shuf -i 1-500 -n 100\" =============\n";
./push_swap --bench $(cat shuffle_numbers.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap $(cat shuffle_numbers.txt) | "$checker" $(cat shuffle_numbers.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $(cat shuffle_numbers.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }

shuf -i 1-500 -n 100 > shuffle_numbers.txt;

echo "\n============= ./push_swap \"shuf -i 1-500 -n 100\" =============\n";
./push_swap --bench $(cat shuffle_numbers.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap $(cat shuffle_numbers.txt) | "$checker" $(cat shuffle_numbers.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $(cat shuffle_numbers.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }

shuf -i 1-500 -n 100 > shuffle_numbers.txt;

echo "\n============= ./push_swap \"shuf -i 1-500 -n 100\" =============\n";
./push_swap --bench $(cat shuffle_numbers.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap $(cat shuffle_numbers.txt) | "$checker" $(cat shuffle_numbers.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap $(cat shuffle_numbers.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --simple \"shuf -i 1-200 -n 50\" =============\n";
./push_swap --bench --simple $(cat shuffle_numbers2.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --simple $(cat shuffle_numbers2.txt) | "$checker" $(cat shuffle_numbers2.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --simple $(cat shuffle_numbers2.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --medium \"shuf -i 1-200 -n 50\" =============\n";
./push_swap --bench --medium $(cat shuffle_numbers2.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --medium $(cat shuffle_numbers2.txt) | "$checker" $(cat shuffle_numbers2.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --medium $(cat shuffle_numbers2.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --complex \"shuf -i 1-200 -n 50\" =============\n";
./push_swap --bench --complex $(cat shuffle_numbers2.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --complex $(cat shuffle_numbers2.txt) | "$checker" $(cat shuffle_numbers2.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --complex $(cat shuffle_numbers2.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --adaptive \"shuf -i 1-200 -n 50\" =============\n";
./push_swap --bench --adaptive $(cat shuffle_numbers2.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --adaptive $(cat shuffle_numbers2.txt) | "$checker" $(cat shuffle_numbers2.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --adaptive $(cat shuffle_numbers2.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }


echo "\n============= ./push_swap --adaptive \"shuf -i 1-1000 -n 500\" =============\n";
./push_swap --bench --adaptive $(cat shuffle_numbers3.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --adaptive $(cat shuffle_numbers3.txt) | "$checker" $(cat shuffle_numbers3.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --adaptive $(cat shuffle_numbers3.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }

shuf -i 1-1000 -n 500 > shuffle_numbers3.txt;

echo "\n============= ./push_swap --adaptive \"shuf -i 1-1000 -n 500\" =============\n";
./push_swap --bench --adaptive $(cat shuffle_numbers3.txt) 2>&1 | grep -C 1 "strategy"
echo "Checker output: \c";

res=$(./push_swap --adaptive $(cat shuffle_numbers3.txt) | "$checker" $(cat shuffle_numbers3.txt))
format_checker_result "$res"

echo "Valgrind: \c";
valgrind ./push_swap --adaptive $(cat shuffle_numbers3.txt) 2>&1 \
| grep -q "All heap blocks were freed -- no leaks are possible" \
&& echo "${VERT}OK${NC}" || { echo -e "${ROUGE}KO${NC}"; SUCCESS=0; }

case "$SUCCESS" in
        1)
            echo "${JAUNE}\nVICTOIRE ! 🥇${NC}"
            ;;
        0)
            echo "${ROUGE}\nDéfaite... 👹${NC}"
            ;;
        *)
            echo ""
            ;;
esac