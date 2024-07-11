SELECT 
    ind.name AS IndexName,
    ind.type_desc AS IndexType,
    col.name AS ColumnName
FROM 
    sys.indexes ind
INNER JOIN 
    sys.index_columns ic ON ind.object_id = ic.object_id AND ind.index_id = ic.index_id
INNER JOIN 
    sys.columns col ON ic.object_id = col.object_id AND ic.column_id = col.column_id
INNER JOIN 
    sys.tables t ON ind.object_id = t.object_id
WHERE 
    t.name = 'Banking' 
    AND ind.is_unique = 1;

ALTER TABLE Banking
DROP CONSTRAINT PK__Banking__3214EC073786FDAC;

