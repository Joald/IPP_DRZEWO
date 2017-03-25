if [ $1 = "-v" ] ; then
	for f in $3/*.in; do 
		./$2 -v <$f 2> "diag.err" | diff -q - "${f%.*}.out";
		diff -q "diag.err" "${f%.*}.err";
	done
	rm "diag.err"
else
	for f in $2/*.in; do 
		./$1 <$f | diff -q - "${f%.*}.out";
	done
fi
