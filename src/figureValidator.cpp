#pragma once
#include <figureValidator.h>

// bool FigureValidator::validate(const std::type_info& type, std::vector<Point2D>& points) {
//     for (int i = 0; i < validators.size(); ++i) {
//         FigureValidator* validator = validators[i];
//         if (validator->isAllowedFor(type)) {
//             bool ok = validator->validate(points);

//             if (!ok) {
//                 // Возможно стОит бросать ошибку
//                 return false;
//             }
//         }
//     }

//     return true;
// }