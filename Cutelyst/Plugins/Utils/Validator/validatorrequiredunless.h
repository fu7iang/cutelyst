/*
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
#ifndef CUTELYSTVALIDATORREQUIREDUNLESS_H
#define CUTELYSTVALIDATORREQUIREDUNLESS_H

#include <Cutelyst/cutelyst_global.h>
#include "validatorrule.h"

namespace Cutelyst {
    
class ValidatorRequiredUnlessPrivate;

/*!
 * \brief The field under validation must be present and not empty unless the other field is equal to any value in the list.
 *
 * If the other field specified as \a otherField does \b not conaint \b any of the values specified in the \a otherValues list, the
 * \a field under validation must be present and not empty.
 *
 * If ValidatorRule::trimBefore() is set to \c true (the default), whitespaces will be removed from
 * the beginning and the end of the input value before validation. So, fields that only contain whitespaces
 * will be treated as empty.
 *
 * \link Validator See Validator for general usage of validators. \endlink
 *
 * \sa ValidatorRequired, ValidatorRequiredIf, ValidatorRequiredWith, ValidatorRequiredWithAll, ValidatorRequiredWithout, ValidatorRequiredWithoutAll
 */
class CUTELYST_PLUGIN_UTILS_VALIDATOR_EXPORT ValidatorRequiredUnless : public ValidatorRule
{
public:
    /*!
     * \brief Constructs a new required unless validator.
     * \param field         Name of the input field to validate.
     * \param otherField    Name of the other input field to validate.
     * \param otherValues   List of values that are not allowed to be in the other field to require the main field.
     * \param label         Human readable input field label, used for generic error messages.
     * \param customError   Custom error message if validation fails.
     */
    ValidatorRequiredUnless(const QString &field, const QString &otherField, const QStringList &otherValues, const QString &label = QString(), const QString &customError = QString());
    
    /*!
     * \brief Deconstructs the required unless validator.
     */
    ~ValidatorRequiredUnless();
    
    /*!
     * \brief Performs the validation and returns an empty QString on success, otherwise an error message.
     */
    QString validate() const override;

    /*!
     * \brief Sets the name of the other field.
     */
    void setOtherField(const QString &otherField);

    /*!
     * \brief Sets the comparative values for the other field.
     */
    void setOtherValues(const QStringList &otherValues);
    
protected:
    /*!
     * \brief Returns a generic error message.
     */
    QString genericValidationError() const override;
    
    /*!
     * Constructs a new ValidatorRequiredUnless object with the given private class.
     */
    ValidatorRequiredUnless(ValidatorRequiredUnlessPrivate &dd);
    
private:
    Q_DECLARE_PRIVATE(ValidatorRequiredUnless)
    Q_DISABLE_COPY(ValidatorRequiredUnless)
};
    
}

#endif //CUTELYSTVALIDATORREQUIREDUNLESS_H

