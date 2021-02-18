# API and Other things for dev

## Concept

### Run
针对一个项目的完整扫描，需包含如下信息
- rid
- hashtag 是否针对同一个项目之类的(zip之后hash)
- target 目标路径
- count 目标总数
- name 扫描任务名
- status 已扫描数
- scan_date 扫描时间
- score 评分

### Task
针对某一个文件的扫描，需包含如下信息
- tid task id
- rid 标记所属的run
- filename 文件路径
- hashtag hash值
- lang 语言
- score 评分
- results
    - policy 匹配的审计策略
    - description 描述
    - score 危险评分
    - type 所属类型
    - scanner 报告来源
    - pos 漏洞位置(line no.)

### Batch
内置方法扫描相关，包含多个Task

## Json Server Api

### /v1/runs/
| Method | URI | Description | 
| ---- | ----- | ---- |
| POST |  /v1/runs/ | 由扫描器发出，新建一个run |
| GET  |  /v1/runs/ | 公开接口， 获取runs列表 |
| GET  |  /v1/runs/<run_id> | 公开接口， 获取对应run的信息 |
| DELETE | /v1/runs/<run_id> | 公开接口， 允许删除对应任务 |
| PATCH | /v1/runs/<run_id> | 公开接口， 允许更新run |

### /v1/tasks/
| Method | URI | Description | Parameter | 
| ---- | ----- | ---- | ---- |
| POST |  /v1/tasks/ | 由扫描器发出，创建task |
| GET  |  /v1/tasks/ | 公开接口， 获取tasks列表 |
| GET  |  /v1/tasks/<run_id> | 公开接口， 获取某个run下对应task的信息 | tid 获取具体的tid对应task
| DELETE | /v1/tasks/<run_id> | 公开接口， 允许删除某个run下所有对应task | tid 获取具体tid对应task


### /v1/status/
| Method | URI | Description | 
| ---- | ----- | ---- |
| GET | /v1/status | 获取json服务器当前状态
| POST | /v1/status | renew服务器状态



## Json Server Data Format


## State Machine

## DataBase Design

3 Collections

### Run
- rid - Char
- hashtag - Char
- target_path - Char
- count - Integer
- scan_name - Char
- scan_date - Date
- score - Float

### Task
- tid - Char
- rid - Char - related run (we can find the related run by using this filed)
- filename - Char
- hashtag - Char
- language - Integer
- score - Float

### Report
- tid - Char - related task
- policy - Char
- description - Char
- score - Float 
- vuln_type - Char
- scanner - Char
- position - Char