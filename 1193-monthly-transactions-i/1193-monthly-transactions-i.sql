# Write your MySQL query statement below
select left(trans_date,7) as month,
country,
count(*)as trans_count,
SUM(case when state="approved" then 1 else 0 end) as approved_count,
SUM(amount) as trans_total_amount,
SUM(case when state="approved" then amount else 0 end) as approved_total_amount

FROM Transactions
GROUP BY month, country