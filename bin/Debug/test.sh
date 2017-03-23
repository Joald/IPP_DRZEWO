for f in *.out; do 
	if diff $f <(sort -n ${f%out}in) >/dev/null 2>&1; then 
		echo OK; 
	else 
		echo "Źle"; 
		fi;\
done