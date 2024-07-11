CREATE TABLE [dbo].[Banking] (
    [Id]          INT NOT NULL IDENTITY,
    [Address]     VARCHAR (50) NOT NULL,
    [AccountType] VARCHAR (50) NOT NULL,
    [PhoneNumber] VARCHAR (50) NOT NULL,
    [Username]    VARCHAR (50) NOT NULL,
    [Password]    VARCHAR (50) NOT NULL,
    [Userbalance] VARCHAR (50) NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC),
    UNIQUE NONCLUSTERED ([AccountType] ASC)
);

