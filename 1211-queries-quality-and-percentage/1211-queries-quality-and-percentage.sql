# Write your MySQL query statement below

select query_name,

            ROUND(AVG(rating/position),2) as quality,

           ROUND(SUM(CASE WHEN rating <3 then 1 else 0 end)/COUNT(*) * 100,2) as poor_query_percentage
  
from Queries
group by query_name