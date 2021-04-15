#curl http://localhost:5000/todos
#curl http://localhost:5000/todos/todo3
#curl http://localhost:5000/todos/todo2 -X DELETE -v
#curl http://localhost:5000/todos -d "task=something new" -X POST -v
#curl http://localhost:5000/todos/todo3 -d "task=something different" -X PUT -v

curl localhost:5000/v1/runs -X POST -d "rid=2020021901" -d "scan_name=test" -d "hashtag=123456abcdef" -d "target_path=test/" -d "count=5" -d "scan_date=2020221" -d "scan_status=3"


