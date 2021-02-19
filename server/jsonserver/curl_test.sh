#curl http://localhost:5000/todos
#curl http://localhost:5000/todos/todo3
#curl http://localhost:5000/todos/todo2 -X DELETE -v
#curl http://localhost:5000/todos -d "task=something new" -X POST -v
#curl http://localhost:5000/todos/todo3 -d "task=something different" -X PUT -v

curl http://localhost:5000/v1/runs -d "rid=2020021901" -d "scan_name=test" -d "hashtag=123456abcdef" -d "target_path=test/" -d "count=5" -d "scan_date=20200221" -d "score=4.0" -d "status=3"  -X POST -v

