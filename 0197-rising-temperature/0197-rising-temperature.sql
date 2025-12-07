# Write your MySQL query statement below
SELECT today.id
FROM Weather AS today
WHERE EXISTS (
    SELECT 1
    FROM Weather AS yesterday
    WHERE DATEDIFF(today.recordDate, yesterday.recordDate) = 1
      AND today.temperature > yesterday.temperature
);
