<< comment
Author: Sadie Thomas
Date: 1/15/2022
Description: Runs executable on input files and checks results against answer file
Instructions: Compile code to executable named ./a.out then run $time bash run_tests.sh
comment

#runs against all .in and .ans files in the ./data/sample directory (change path if necessary)
for f in ./data/sample/*.in ; 
	do 	./a.out < "$f" > my_output.txt; 
		diff "${f%.in}.ans" my_output.txt;
		rv=$?
		if [[ $rv == 1 ]]
		then 
			echo "Failed test $f"
		else
			echo "Passed test $f"
		fi
	done

#runs against all .in and .ans files in the /data/secret directory
for f in ./data/secret/*.in ; 
	do 	./a.out < "$f" > my_output.txt; 
		diff "${f%.in}.ans" my_output.txt;
		rv=$?
		if [[ $rv == 1 ]]
		then 
			echo "Failed test $f"
		else
			echo "Passed test $f"
		fi
	done
