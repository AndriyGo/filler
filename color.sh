gren=$(printf "\033[33mO\033[0m")
yel=$(printf "\033[34mX\033[0m")
grens=$(printf "\033[32mo\033[0m")
yel2=$(printf "\033[30mx\033[0m")

sed "s|O|$gren|g" |
sed "s|X|$yel|g" |
sed "s|x|$yel2|g" |
sed "/^0.. /s|o|$grens|g" |
sed "s|fin|player|g" 