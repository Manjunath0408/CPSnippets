set -e
g++ solution.cpp -o solution
g++ generator.cpp -o generator
g++ brute.cpp -o brute
for((i = 1; ; ++i)); do
    ./generator $i > input_file
    ./solution < input_file > myAnswer
    ./brute < input_file > correctAnswer
    diff -Z myAnswer correctAnswer > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer
