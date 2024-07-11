SELECT 
    con.name AS ConstraintName,
    con.type_desc AS ConstraintType
FROM 
    sys.objects AS con
JOIN 
    sys.objects AS tbl
    ON con.parent_object_id = tbl.object_id
WHERE 
    tbl.name = 'Banking'
    AND con.type_desc = 'UNIQUE_CONSTRAINT';
