#curl http://localhost:5000/todos
#curl http://localhost:5000/todos/todo3
#curl http://localhost:5000/todos/todo2 -X DELETE -v
#curl http://localhost:5000/todos -d "task=something new" -X POST -v
#curl http://localhost:5000/todos/todo3 -d "task=something different" -X PUT -v

curl localhost:5000/v1/runs -X POST -d "rid=1" -d "scan_name=test" -d "hashtag=123456abcdef" -d "target_path=test/" -d "count=5" -d "scan_date=2020221" -d "scan_status=3"

curl localhost:5000/v1/tasks -X POST -d "filename=test/check1.cpp" -d "tid=1" -d "rid=1" -d "hashtag=nicetomeetyou" -d "language=cpp" -d "level=warning" -d "message=this is a message" -d "pos=22:10, 22:11" -d "rule=mine_rule"

curl localhost:5000/v1/tasks -X POST -d "filename=test/error_src.cpp" -d "tid=2" -d "rid=1" -d "hashtag=filehere" -d "language=cpp" -d "level=warning" -d "message=rulehere" -d "pos=12:16, 22:11" -d "rule=mine_rule"
