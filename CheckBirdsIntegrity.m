function Birds = CheckBirdsIntegrity(Birds)
% Script for checking bird .mat files data integrity (created after bugs in
% module updates 25/06/2015)

o = 1;
duplicates = 0;
errorsOnGood = 0;
transFound = 0;
badDataWiped = 0;
skipsFound = 0;
noTrans = 0;
wipeDuplicates = true;
wipeMissingData = true;
removeErsOnGoodData = true;
removeNotTranslated = false;
removeSkips = false;

disp('Checking integrity of saved bird data...');

try
    while o <= numel(Birds)
        % If the translation has been done, remove any skip/error data
        if removeErsOnGoodData
            if isfield(Birds{o},'Translation');
                noErs = true;
                transFound = transFound + 1;
                if isfield(Birds{o},'skip')
                    Birds{o} = rmfield(Birds{o},'skip'); %#ok<*SAGROW>
                    noErs = false;
                end
                if isfield(Birds{o},'er')
                    Birds{o} = rmfield(Birds{o},'er');
                    noErs = false;
                end
                if isfield(Birds{o},'error')
                    Birds{o} = rmfield(Birds{o},'error');
                    noErs = false;
                end
                if isfield(Birds{o},'possible') && ~Birds{o}.possible
                    Birds{o}.possible = true;
                    noErs = false;
                end
                
                if ~noErs
                    % Track the above
                    errorsOnGood = errorsOnGood + 1;
                end
                
            else
                if removeNotTranslated
                    Birds(o) = [];
                    o = o - 1;
                end
                noTrans = noTrans + 1;
            end
            
        end
        
        if wipeMissingData
            if      ~isfield(Birds{o},'Frame_Number') || ...
                    ~isfield(Birds{o},'Marker_Number') || ...
                    ~isfield(Birds{o},'Reel_Number')
                % If any essential fields are not present, scrap this bird data
                badDataWiped = badDataWiped + 1;
                Birds(o) = [];
                o = o - 1;
            end
        end
        
        
        if isfield(Birds{o},'skip')
            if removeSkips
                Birds(o) = [];
                o = o - 1;
            end
            skipsFound = skipsFound + 1;
        end
            
        
        if wipeDuplicates
            for m = 1 : o %#ok<*UNRCH>
                if m == o
                    continue
                end
                if      Birds{o}.Frame_Number == Birds{m}.Frame_Number && ...
                        Birds{o}.Marker_Number == Birds{m}.Marker_Number && ...
                        strcmp(Birds{o}.Reel_Number,Birds{m}.Reel_Number)
                    duplicates = duplicates + 1;
                    Birds(m) = [];
                    o = o - 1;
                end
                
            end
        end
        
        % Next stage of loop
        o = o + 1;
        
    end
    disp(   [num2str(duplicates)  ' duplicates (deleted)... ' 10 ...
            num2str(noTrans)      ' birds without translations... ' 10 ...
            num2str(badDataWiped) ' birds with missing data (deleted)... ' 10 ...
            num2str(skipsFound) ' birds to be skipped...' 10 ...
            num2str(errorsOnGood) ' bad fields on good data (deleted)...' 10 ...
            'Integrity check complete.']);
catch %#ok<CTCH>
end