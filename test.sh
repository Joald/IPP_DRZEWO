for f in tests/*.in; do ./test <$f | diff - "${f%.*}.out";done
