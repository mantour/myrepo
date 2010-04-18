# -*- coding: utf-8 -*-
"""This module contains the data model of the application."""


import pkg_resources
pkg_resources.require("SQLObject>=0.10.1")

from turbogears.database import PackageHub
# import some basic SQLObject classes for declaring the data model
# (see http://www.sqlobject.org/SQLObject.html#declaring-the-class)
from sqlobject import SQLObject, SQLObjectNotFound, RelatedJoin
from sqlobject.inheritance import InheritableSQLObject
# import some datatypes for table columns from SQLObject
# (see http://www.sqlobject.org/SQLObject.html#column-types for more)
from sqlobject import StringCol, UnicodeCol, IntCol, DateTimeCol

__connection__ = hub = PackageHub('bookmark')


# your data model

class Bookmark(SQLObject):
    name=UnicodeCol(alternateID=True, length=100)
    link=UnicodeCol()
    description=UnicodeCol()

# class YourDataClass(SQLObject):
#     pass



# functions for populating the database

def bootstrap_model(clean=False):
    """Create all database tables and fill them with default data.

    This function is run by the 'bootstrap' function from the command module.
    By default it creates all database tables for your model.

    You can add more functions as you like to add more boostrap data to the
    database or enhance the function below.

    If 'clean' is True, all tables defined by your model will be dropped before
    creating them again.

    """
    create_tables(clean)

def create_tables(drop_all=False):
    """Create all tables defined in the model in the database.

    Optionally drop existing tables before creating them.

    """
    from turbogears.util import get_model
    from inspect import isclass

    model = get_model()
    if not model:
        from bookmark.command import ConfigurationError
        raise ConfigurationError(
            "Unable to create database tables without a model")

    try:
        so_classes = [model.__dict__[x] for x in model.soClasses]
    except AttributeError:
        so_classes = model.__dict__.values()

    if drop_all:
        print "Dropping all database tables defined in model."
        for item in reversed(so_classes):
            if isclass(item) and issubclass(item, SQLObject) and \
                    item is not SQLObject and item is not InheritableSQLObject:
                item.dropTable(ifExists=True, cascade=True)

    # list of constraints we will collect
    constraints = list()

    for item in so_classes:
        if isclass(item) and issubclass(item, SQLObject) and \
                item is not SQLObject and item is not InheritableSQLObject:
            # create table without applying constraints, collect
            # all the constaints for later creation.
            # see http://sqlobject.org/FAQ.html#mutually-referencing-tables
            # for more info
            collected_constraints = item.createTable(ifNotExists=True,
                applyConstraints=False)

            if collected_constraints:
                constraints.extend(collected_constraints)

    # now that all tables are created, add the constaints we collected
    for postponed_constraint in constraints:
        # item is the last processed item and we borrow its connection
        item._connection.query(postponed_constraint)

    print "All database tables defined in model created."

