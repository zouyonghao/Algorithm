#
# [183] Customers Who Never Order
#
# https://leetcode-cn.com/problems/customers-who-never-order/description/
#
# database
# Easy (50.62%)
# Total Accepted:    4.3K
# Total Submissions: 8.4K
# Testcase Example:  '{"headers": {"Customers": ["Id", "Name"], "Orders": ["Id", "CustomerId"]}, "rows": {"Customers": [[1, "Joe"], [2, "Henry"], [3, "Sam"], [4, "Max"]], "Orders": [[1, 3], [2, 1]]}}'
#
# 某网站包含两个表，Customers 表和 Orders 表。编写一个 SQL 查询，找出所有从不订购任何东西的客户。
# 
# Customers 表：
# 
# +----+-------+
# | Id | Name  |
# +----+-------+
# | 1  | Joe   |
# | 2  | Henry |
# | 3  | Sam   |
# | 4  | Max   |
# +----+-------+
# 
# 
# Orders 表：
# 
# +----+------------+
# | Id | CustomerId |
# +----+------------+
# | 1  | 3          |
# | 2  | 1          |
# +----+------------+
# 
# 
# 例如给定上述表格，你的查询应返回：
# 
# +-----------+
# | Customers |
# +-----------+
# | Henry     |
# | Max       |
# +-----------+
# 
# 
#
# Write your MySQL query statement below

select Name Customers from Customers where Id not in (
    select c.Id from Customers c join Orders o on c.Id = o.CustomerId)