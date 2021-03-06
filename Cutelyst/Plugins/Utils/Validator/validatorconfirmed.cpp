﻿/*
 * Copyright (C) 2017 Matthias Fehring <kontakt@buschmann23.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "validatorconfirmed_p.h"

using namespace Cutelyst;

ValidatorConfirmed::ValidatorConfirmed(const QString &field, const QString &label, const QString &customError) :
    ValidatorRule(*new ValidatorConfirmedPrivate(field, label, customError))
{
}

ValidatorConfirmed::ValidatorConfirmed(ValidatorConfirmedPrivate &dd) :
    ValidatorRule(dd)
{
}

ValidatorConfirmed::~ValidatorConfirmed()
{
}

QString ValidatorConfirmed::validate() const
{
    QString result;

    if (!value().isEmpty()) {
        const QString ofn = field() + QLatin1String("_confirmation");

        if (value() != parameters().value(ofn)) {
            result = validationError();
        }
    }

    return result;
}

QString ValidatorConfirmed::genericValidationError() const
{
    QString error;
    if (label().isEmpty()) {
        error = QStringLiteral("Confirmation failed.");
    } else {
        error = QStringLiteral("The content of the “%1” field has not been confirmed.").arg(label());
    }
    return error;
}
