map=("0" "1" "2");
for i in "${map[@]}"; do
    p=1;
    while [ $p -le 2 ]; do
    	won=0;
    	lost=0;
    	seed=0;
    	echo Player $p. Map $i.
    	while [ $seed -lt 1000 ]; do
    		if [ "$p" = 1 ]; then
    			./res/filler_vm -p1 ./agordiyc.filler -p2 ./res/players/carli.filler -f ./res/maps/map0$i -q -s $seed >/dev/null
    		else
    			./res/filler_vm -p2 ./agordiyc.filler -p1 ./res/players/carli.filler -f ./res/maps/map0$i -q -s $seed >/dev/null
    		fi
    		line="$(head -2 ./filler.trace | tail -1)"
    		if [[ $line == *"agordiyc"* ]]; then
				won=$[$won+1];
			else
				lost=$[$lost+1];
			fi
    		echo -en Won $won. Lost $lost
    		seed=$[$seed+1];
    		if [ $seed -lt 1000 ]; then
    			echo -en "\r"
    		else
    			echo ""
    		fi
    	done
    	p=$[$p+1];
    done
done
